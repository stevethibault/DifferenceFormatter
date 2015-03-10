#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>

namespace util
{
    template<typename T>
    std::vector<T> split(const T & str, const T & delimiters);
}

#endif //UTIL_H
