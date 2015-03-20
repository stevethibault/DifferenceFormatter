#ifndef LINE_H
#define LINE_H

#include <string>

namespace Waters
{

class Line
{
    public:
        enum class LineType : char {unchanged = ' ', added = '+', removed = '-', missing = '\0'};

        Line() {}
        Line(LineType lineType) : line_type{lineType} {}

		Line(std::string lineText, int lineNumber, Line::LineType lineType) : Line(lineType)
		{
			line_number = lineNumber;
			if (lineText.length() > 0)
			{
				code = lineText;
			}
		};

		const Line::LineType lineType() const { return line_type; };
		const int lineNumber() const { return line_number; };
		const std::string codeLine() const { return code; };

        ~Line() {}

	private:
		LineType line_type{LineType::missing};
		int line_number{};
		std::string code{};
};

};
#endif // LINE_H
