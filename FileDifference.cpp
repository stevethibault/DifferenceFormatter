#include "FileDifference.h"

namespace Waters
{
Difference::Difference(const std::string& line_numbers)
{
    auto tokens = util::split<std::string>(line_numbers, ",");

    start_line = std::stoi(tokens[0]);
    line_count = std::stoi(tokens[1]);
}

DifferenceSet::DifferenceSet(const std::string& line_numbers)
{
    auto tokens = util::split<std::string>(line_numbers, " ");

    left_difference = Difference(tokens[0]);
    right_difference = Difference(tokens[1]);
}


FileDifferences::FileDifferences(const std::string& input_line) :
    command_line{input_line}
{

}

std::string FileDifferences::commandLine() const
{
    return command_line;
}

void FileDifferences::commandLine(const std::string& command)
{
    command_line = command;
}

Poco::Path FileDifferences::leftFile() const
{
    return left_file;
}

void FileDifferences::leftFile(const std::string& left)
{
    left_file = Poco::Path(left);
}

Poco::Path FileDifferences::rightFile() const
{
    return right_file;
}

void FileDifferences::rightFile(const std::string& right)
{
    right_file = Poco::Path(right);
}

void FileDifferences::addDifferenceSet(DifferenceSet diffSet)
{
    differences.push_back(diffSet);
}

};

