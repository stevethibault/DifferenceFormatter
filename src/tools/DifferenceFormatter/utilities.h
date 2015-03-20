#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>
#include <tuple>
#include <chrono>
#include <ctime>

namespace util
{
	std::string getTime();

	std::string encode(const std::string& data);

    template<typename T>
    std::vector<T> split(const T & str, const T & delimiters)
    {
        std::vector<T> v;
        typename T::size_type start = 0;
        auto pos = str.find_first_of(delimiters, start);

        while(pos != T::npos)
        {
            if(pos != start) // ignore empty tokens
            {
                v.emplace_back(str, start, pos - start);
            }

            start = pos + 1;
            pos = str.find_first_of(delimiters, start);
        }

        if(start < str.length()) // ignore trailing delimiter
        {
            v.emplace_back(str, start, str.length() - start); // add what's left of the string
        }

        return v;
    }

}

#endif //UTIL_H
