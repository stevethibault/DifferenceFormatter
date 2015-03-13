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
        Line(LineType lineType) : lineType{lineType} {}

		Line(std::string lineText, int lineNumber, Line::LineType lineType) : Line(lineType)
		{
			line_number = lineNumber;
			if (lineText.length() > 0)
			{
				code = lineText.substr(1, lineText.length() - 2);
			}
		};

        ~Line() {}

	private:
		LineType lineType{LineType::missing};
		int line_number{};
		std::string code{};
};

};
#endif // LINE_H
