#ifndef FILEDIFFERENCE_H
#define FILEDIFFERENCE_H

#include <Poco/File.h>
#include <Poco/JSON.h>
#include <Poco/JSON/Object.h>
#include <Poco/Path.h>
#include <string>
#include <vector>
#include <pair>

namespace waters
{

class CodeLine : public Line
{
    public:
        CodeLine(std::string line_text)
        {
            lineType = line_text[0];
            code = line_text.substr(1, line_text.length() - 2);
        };

    private:
        int line_number{};
        std::string code{};
};

class Line
{
    public:
        enum class LineType : char {unchanged = ' ', added ='+', removed = '-', missing = '\0'};

        static std::pair<Waters::Line, int> makeLine(const std::string& line_text, const int previous_line_number)
        {
            char line_code;
            int line_number = previous_line_number;

            if (line_text.length() == 0)
            {
                return std::make_pair(Line{LineType::missing}, line_number);
            }
            else
            {
                return std::make_pair(CodeLine{line_text, ++line_number}, line_number);
            }
        }

    protected:
        LineType lineType{LineType::missing};
};

class Difference
{
    private:
        int start_line;
        int line_count;
        vector<Line> lines;
};

class DifferenceSet
{
    private:
        Difference left_difference{};
        Difference right_difference{};
};

class FileDifferences
{
    private:
        std::string diff_commandline{};
        Poco::Path left_file{};
        Poco::Path right_file{};
        std::vector<DifferenceSet> difference_set{};
};

}
#endif //FILEDIFFERENCE_H
