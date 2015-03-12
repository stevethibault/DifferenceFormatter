#ifndef CODELINE_H
#define CODELINE_H

#include "Line.h"
#include <string>
#include <tuple>

namespace Waters
{

class CodeLine : public Line
{
    public:
        CodeLine(std::string line_text, int line_number)
        {
            lineType = static_cast<Line::LineType>(line_text[0]);
            code = line_text.substr(1, line_text.length() - 2);
        };
        ~CodeLine() {}

    private:
        int line_number{};
        std::string code{};
};


};

#endif // CODELINE_H
