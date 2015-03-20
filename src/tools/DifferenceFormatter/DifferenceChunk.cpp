#include "DifferenceChunk.h"

namespace Waters
{

DifferenceChunk::DifferenceChunk(const std::string& line_numbers)
{
	auto tokens = util::split<std::string>(line_numbers, ",");

	start_line = std::stoi(tokens[0].substr(1, tokens[0].length() - 1));
	line_count = std::stoi(tokens[1]);
	current_line_number = start_line;
}

void DifferenceChunk::addLine(const std::string& lineText, Line::LineType lineType)
{

    lines.push_back(Line(lineText, current_line_number, lineType));

	if (lineType != Line::LineType::missing)
    {
		++current_line_number;
    }
}


const std::vector<Line> DifferenceChunk::getLines() const
{
	return lines;
}

};
