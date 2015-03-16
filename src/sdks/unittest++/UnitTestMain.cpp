#include <UnitTest++/UnitTest++.h>
#include <UnitTest++/TestReporterStdout.h>
#include <UnitTest++/XmlTestReporter.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#if defined(__APPLE__) || defined(__GNUG__)
    char const* const errorFormat = "%s:%d: error: Failure in %s: %s\n";
#else
    char const* const errorFormat = "%s(%d): error: Failure in %s: %s\n";
#endif

class VerboseReporter : public UnitTest::TestReporterStdout
{
	typedef UnitTest::TestReporterStdout Base;
public:
    virtual void ReportTestStart(UnitTest::TestDetails const& details)
	{
		m_failure = false;
	}

	virtual void ReportFailure(UnitTest::TestDetails const& details, char const* failure)
	{
		m_failure = true;
		printf(errorFormat, details.filename, details.lineNumber, details.testName, failure);
	}

    virtual void ReportTestFinish(UnitTest::TestDetails const& test, float secondsElapsed)
	{
		std::cout << (m_failure ? "[FAILED]" : "[PASSED]");
		std::cout << " (" << std::fixed << std::setprecision(2) << secondsElapsed << ")";
		std::cout << "  " << test.suiteName << "::" << test.testName << std::endl;
	}
private:
	bool m_failure;
};

int RunTest(UnitTest::TestReporter &reporter)
{
	UnitTest::TestRunner runner(reporter);
	return runner.RunTestsIf(UnitTest::Test::GetTestList(), NULL, UnitTest::True(), 0);
}

int RunVerboseTest()
{
	VerboseReporter reporter;
	return RunTest(reporter);
}

int RunXmlReportTest(char const* reportFilename)
{
	std::ofstream f(reportFilename);
	UnitTest::XmlTestReporter reporter(f);
	return RunTest(reporter);
}

int main(int argc, char const* argv[])
{
	if (argc >= 3)
	{
		if (strcmp(argv[1], "/report") == 0)
		{
			return RunXmlReportTest(argv[2]);
		}
		if (strcmp(argv[1], "/repeat") == 0)
		{
			int repeats = atoi(argv[2]);
			while (repeats--)
			{
				RunVerboseTest();
			}
			return 0;
		}
	}
	return RunVerboseTest();
}
