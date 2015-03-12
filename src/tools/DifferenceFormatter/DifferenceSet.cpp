#include "DifferenceSet.h"

namespace Waters
{

Difference::Difference(const std::string& line_numbers)
{
    auto tokens = util::split<std::string>(line_numbers, ",");

    start_line = std::stoi(tokens[0]);
    line_count = std::stoi(tokens[1]);
}

DifferenceSet::DifferenceSet(const std::string& line_numbers)
{
    auto tokens = util::split<std::string>(line_numbers, " ");

    left_difference = Difference(tokens[0]);
    right_difference = Difference(tokens[1]);
}

void DifferenceSet::addDifference(const std::string& line, Line::LineType lineType)
{
    switch (lineType)
    {
        case Line::LineType::unchanged:
            if (left_lines > right_lines)
            {
                for (int i = 0; i < left_lines - right_lines; ++i)
                {
                    right_difference.addLine("");
                }
            }
            else if (right_lines > left_lines)
            {
                for (int i = 0; i < right_lines -left_lines; ++i)
                {
                    left_difference.addLine("");
                }
            }
            left_difference.addLine(line);
            right_difference.addLine(line);
            break;
        case Line::LineType::removed:
            left_difference.addLine(line);
            ++left_lines;
            break;
        case Line::LineType::added:
            right_difference.addLine(line);
            ++right_lines;
    }
}

};
