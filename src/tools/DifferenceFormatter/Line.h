#ifndef LINE_H
#define LINE_H

namespace Waters
{

class Line
{
    public:
        enum class LineType : char {unchanged = ' ', added = '+', removed = '-', missing = '\0'};

        Line() {}
        Line(LineType line) : lineType{line} {}

        ~Line() {}


    protected:
        LineType lineType{LineType::missing};
};

};
#endif // LINE_H
