#ifndef STREAM_H
#define STREAM_H

#include <istream>
#include <string>
#include <memory>
#include <vector>

namespace util
{
    template<typename T>
    std::vector<T> split(const T & str, const T & delimiters);
}

#endif
 //STREAM_H
