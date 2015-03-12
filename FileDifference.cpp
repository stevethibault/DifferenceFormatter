#include "FileDifference.h"

namespace Waters
{

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

