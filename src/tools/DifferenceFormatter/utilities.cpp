#include "utilities.h"

namespace util
{

	std::string getTime()
	{
		auto tp = std::chrono::system_clock::now();
		auto t = std::chrono::system_clock::to_time_t(tp);
		return std::ctime(&t);
	}

	std::string encode(const std::string& data)
	{
		std::string buffer;
		buffer.reserve(data.size());
		for (size_t pos = 0; pos != data.size(); ++pos)
		{
			switch (data[pos])
			{
			case '&':  buffer.append("&amp;");       break;
			case '\"': buffer.append("&quot;");      break;
			case '\'': buffer.append("&apos;");      break;
			case '<':  buffer.append("&lt;");        break;
			case '>':  buffer.append("&gt;");        break;
			default:   buffer.append(&data[pos], 1); break;
			}
		}

		return buffer;
	}



};

