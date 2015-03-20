#include "DifferenceSet.h"

namespace Waters
{

DifferenceSet::DifferenceSet(const std::string& lineNumbers) : line_numbers(lineNumbers)
{
    auto tokens = util::split<std::string>(line_numbers, " ");

	left_difference = DifferenceChunk(tokens[0]);
	right_difference = DifferenceChunk(tokens[1]);
}

const DifferenceChunk& DifferenceSet::leftDifference() const
{
	return left_difference;
}

const DifferenceChunk& DifferenceSet::rightDifference() const
{
	return right_difference;
}

const std::string& DifferenceSet::lineNumbers() const
{
	return line_numbers;
}

void DifferenceSet::addDifference(const std::string& line)
{
	Line::LineType lineType;
	std::string newLine;

	if (line.length() == 0)
	{
		lineType = Line::LineType::unchanged;
		newLine = line;
	}
	else
	{
		lineType = static_cast<Line::LineType>(line[0]);
		newLine = line.substr(1, line.length() - 1);
	}

    switch (lineType)
    {
        case Line::LineType::unchanged:

            if (left_lines > right_lines)
            {
				BalanceWithBlankLines(right_difference, left_lines - right_lines);
				right_lines = left_lines;
            }
            else if (right_lines > left_lines)
            {
				BalanceWithBlankLines(left_difference, right_lines - left_lines);
				left_lines = right_lines;
			}

			left_difference.addLine(newLine, lineType);
			right_difference.addLine(newLine, lineType);
            break;
        case Line::LineType::removed:
			left_difference.addLine(newLine, lineType);
            ++left_lines;
            break;
        case Line::LineType::added:
			right_difference.addLine(newLine, lineType);
            ++right_lines;
			break;
    }
}

void DifferenceSet::BalanceWithBlankLines(DifferenceChunk &difference, int imbalance)
{
	for (int i = 0; i < imbalance; ++i)
	{
		difference.addLine("", Line::LineType::missing);
	}

}
};
