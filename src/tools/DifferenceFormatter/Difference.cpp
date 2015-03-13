#include "Difference.h"

namespace Waters
{

Difference::Difference(const std::string& line_numbers)
{
	auto tokens = util::split<std::string>(line_numbers, ",");

	start_line = std::stoi(tokens[0].substr(1, tokens[0].length() - 1));
	line_count = std::stoi(tokens[1]);
	current_line_number = start_line;
}

void Difference::addLine(const std::string& lineText, Line::LineType lineType)
{

    lines.push_back(Line(lineText, current_line_number, lineType));

	if (lineType != Line::LineType::missing)
    {
		++current_line_number;
    }
}

};
