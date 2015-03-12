#ifndef DIFFERENCE_H
#define DIFFERENCE_H

#include "Line.h"
#include <string>
#include <vector>

namespace Waters
{

class Difference
{
    public:
        Difference(){}
        Difference(const std::string& line_range);
        ~Difference(){}

    void addLine(const std::string& line_text);

    private:
        int start_line{};
        int line_count{};
        int current_line_number{};
        std::vector<Line> lines{};
};

};

#endif // DIFFERENCE_H
