//
// Process_UNIX.cpp
//
// $Id: //poco/1.4/Foundation/src/Process_UNIX.cpp#3 $
//
// Library: Foundation
// Package: Processes
// Module:  Process
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/Process_UNIX.h"
#include "Poco/Exception.h"
#include "Poco/NumberFormatter.h"
#include "Poco/Pipe.h"
#include <errno.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>


#if defined(__QNX__)
#include <process.h>
#include <spawn.h>
#include <cstring>
#endif


namespace Poco {


//
// ProcessHandleImpl
//
ProcessHandleImpl::ProcessHandleImpl(pid_t pid):
	_pid(pid),
	_exitStatus(-1)
{
}


ProcessHandleImpl::~ProcessHandleImpl()
{
}


pid_t ProcessHandleImpl::id() const
{
	return _pid;
}


int ProcessHandleImpl::wait() const
{
	int rc;
	do
	{
		rc = waitpid(_pid, &_exitStatus, 0);
	}
	while (rc < 0 && errno == EINTR);
	if (rc != _pid)
		throw SystemException("Cannot wait for process", NumberFormatter::format(_pid));
	return WEXITSTATUS(_exitStatus);
}


bool ProcessHandleImpl::tryWait(int timeoutInMilliseconds) const
{
	Poco::Timestamp now;
	while(isAlive())
	{
		Poco::Timestamp::TimeDiff diff = now.elapsed();
		int ms = diff / 1000;
		if( ms >= timeoutInMilliseconds )
			break;
	}
	return !isAlive();
}


int ProcessHandleImpl::exitCode() const
{
	if (_exitStatus == -1)
		throw SystemException("Cannot get exit code for process", NumberFormatter::format(_pid));

	return WEXITSTATUS(_exitStatus);
}


bool ProcessHandleImpl::isAlive() const
{
	if (_exitStatus != -1)
		return false;
	
	int status;
	pid_t result = waitpid(_pid, &status, WNOHANG);
	if (result == -1 || result == _pid)
	{
		_exitStatus = status;
		return false;
	}
		
    return true;
}

//
// ProcessImpl
//
ProcessImpl::PIDImpl ProcessImpl::idImpl()
{
	return getpid();
}


void ProcessImpl::timesImpl(long& userTime, long& kernelTime)
{
	struct rusage usage;
	getrusage(RUSAGE_SELF, &usage);
	userTime   = usage.ru_utime.tv_sec;
	kernelTime = usage.ru_stime.tv_sec;
}


ProcessHandleImpl* ProcessImpl::launchImpl(const std::string& command, const ArgsImpl& args, const std::string& initialDirectory, Pipe* inPipe, Pipe* outPipe, Pipe* errPipe, const EnvImpl& env)
{
#if defined(__QNX__)
	if (initialDirectory.empty())
	{
		/// use QNX's spawn system call which is more efficient than fork/exec.
		char** argv = new char*[args.size() + 2];
		int i = 0;
		argv[i++] = const_cast<char*>(command.c_str());
		for (ArgsImpl::const_iterator it = args.begin(); it != args.end(); ++it) 
			argv[i++] = const_cast<char*>(it->c_str());
		argv[i] = NULL;
		struct inheritance inherit;
		std::memset(&inherit, 0, sizeof(inherit));
		inherit.flags = SPAWN_ALIGN_DEFAULT | SPAWN_CHECK_SCRIPT | SPAWN_SEARCH_PATH;
		int fdmap[3];
		fdmap[0] = inPipe  ? inPipe->readHandle()   : 0;
		fdmap[1] = outPipe ? outPipe->writeHandle() : 1;
		fdmap[2] = errPipe ? errPipe->writeHandle() : 2;
	
		char** envPtr = 0;
		std::vector<char> envChars;
		std::vector<char*> envPtrs;
		if (!env.empty())
		{
			envChars = getEnvironmentVariablesBuffer(env);
			envPtrs.reserve(env.size() + 1);
			char* p = &envChars[0];
			while (*p)
			{
				envPtrs.push_back(p);
				while (*p) ++p;
				++p;
			}
			envPtrs.push_back(0);
			envPtr = &envPtrs[0];
		}
	
		int pid = spawn(command.c_str(), 3, fdmap, &inherit, argv, envPtr);
		delete [] argv;
		if (pid == -1) 
			throw SystemException("cannot spawn", command);

		if (inPipe)  inPipe->close(Pipe::CLOSE_READ);
		if (outPipe) outPipe->close(Pipe::CLOSE_WRITE);
		if (errPipe) errPipe->close(Pipe::CLOSE_WRITE);
		return new ProcessHandleImpl(pid);
	}
	else
	{
		return launchByForkExecImpl(command, args, initialDirectory, inPipe, outPipe, errPipe, env);
	}
#else
	return launchByForkExecImpl(command, args, initialDirectory, inPipe, outPipe, errPipe, env);
#endif
}


ProcessHandleImpl* ProcessImpl::launchByForkExecImpl(const std::string& command, const ArgsImpl& args, const std::string& initialDirectory, Pipe* inPipe, Pipe* outPipe, Pipe* errPipe, const EnvImpl& env)
{
	int pid = fork();
	if (pid < 0)
	{
		throw SystemException("Cannot fork process for", command);		
	}
	else if (pid == 0)
	{
		if (!initialDirectory.empty())
		{
			if (chdir(initialDirectory.c_str()) != 0)
			{
				_exit(72);
			}
		}

		setEnvironmentVariables(env);

		// setup redirection
		if (inPipe)
		{
			dup2(inPipe->readHandle(), STDIN_FILENO);
			inPipe->close(Pipe::CLOSE_BOTH);
		}
		// outPipe and errPipe may be the same, so we dup first and close later
		if (outPipe) dup2(outPipe->writeHandle(), STDOUT_FILENO);
		if (errPipe) dup2(errPipe->writeHandle(), STDERR_FILENO);
		if (outPipe) outPipe->close(Pipe::CLOSE_BOTH);
		if (errPipe) errPipe->close(Pipe::CLOSE_BOTH);
		// close all open file descriptors other than stdin, stdout, stderr
		for (int i = 3; i < getdtablesize(); ++i)
			close(i);

		char** argv = new char*[args.size() + 2];
		int i = 0;
		argv[i++] = const_cast<char*>(command.c_str());
		for (ArgsImpl::const_iterator it = args.begin(); it != args.end(); ++it) 
			argv[i++] = const_cast<char*>(it->c_str());
		argv[i] = NULL;
		execvp(command.c_str(), argv);
		_exit(72);
	}

	if (inPipe)  inPipe->close(Pipe::CLOSE_READ);
	if (outPipe) outPipe->close(Pipe::CLOSE_WRITE);
	if (errPipe) errPipe->close(Pipe::CLOSE_WRITE);
	return new ProcessHandleImpl(pid);
}


void ProcessImpl::killImpl(ProcessHandleImpl& handle)
{
	killImpl(handle.id());
}


void ProcessImpl::killImpl(PIDImpl pid)
{
	if (kill(pid, SIGKILL) != 0)
	{
		switch (errno)
		{
		case ESRCH:
			throw NotFoundException("cannot kill process");
		case EPERM:
			throw NoPermissionException("cannot kill process");
		default:
			throw SystemException("cannot kill process");
		}
	}
}


void ProcessImpl::requestTerminationImpl(PIDImpl pid)
{
	if (kill(pid, SIGINT) != 0)
	{
		switch (errno)
		{
		case ESRCH:
			throw NotFoundException("cannot terminate process");
		case EPERM:
			throw NoPermissionException("cannot terminate process");
		default:
			throw SystemException("cannot terminate process");
		}
	}
}


} // namespace Poco