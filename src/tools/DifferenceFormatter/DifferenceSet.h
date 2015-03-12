#ifndef DIFFERENCESET_H
#define DIFFERENCESET_H

#include "Difference.h"
#include "utilities.h"
#include <string>

namespace Waters
{

class DifferenceSet
{
    public:
        DifferenceSet() {}
        DifferenceSet(const std::string& line_numbers);

        Difference& leftDifference();
        Difference& rigthDifference();

        void addDifference(const std::string& line, Line::LineType lineType);

    private:
        Difference left_difference{};
        Difference right_difference{};
        int left_lines{};
        int right_lines{};
};

};

#endif // DIFFERENCESET_H
