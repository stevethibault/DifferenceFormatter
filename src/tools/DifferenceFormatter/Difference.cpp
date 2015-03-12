#include "Difference.h"

#include "CodeLine.h"

namespace Waters
{

void Difference::addLine(const std::string& line_text)
{

    if (line_text.length() == 0)
    {
        lines.push_back(Line{Line::LineType::missing});
    }
    else
    {
        lines.push_back(CodeLine{line_text, ++current_line_number});
    }
}

};
