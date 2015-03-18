#include "utilities.h"

namespace util
{

	std::string getTime()
	{
		auto tp = std::chrono::system_clock::now();
		auto t = std::chrono::system_clock::to_time_t(tp);
		return std::ctime(&t);
	}

};

