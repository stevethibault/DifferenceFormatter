#ifndef CODELINE_H
#define CODELINE_H

#include "Line.h"
#include <string>
#include <tuple>

namespace Waters
{

std::pair<int, Waters::Line> make_line(std::string lineText, Line::LineType lineType, int lineNumber);

class CodeLine : public Line
{
    public:
		CodeLine(std::string lineText, int line_number, Line::LineType lineType) : Line(lineType)
        {
            
			if (lineText.length() > 0)
			{
				code = lineText.substr(1, lineText.length() - 2);
			}
        };
        ~CodeLine() {}

    private:
        int line_number{};
        std::string code{};
};

};

#endif // CODELINE_H
