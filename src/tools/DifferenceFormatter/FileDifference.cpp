#include "FileDifference.h"

namespace Waters
{

FileDifferences::FileDifferences(const std::string& input_line) :
    line(input_line)
{

}

std::string FileDifferences::commandLine() const
{
    return line;
}

void FileDifferences::commandLine(const std::string& command)
{
    line = command;
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

void FileDifferences::addDifferenceSet(std::shared_ptr<DifferenceSet> diffSet)
{
    differences.push_back(diffSet);
}

const std::vector<std::shared_ptr<DifferenceSet>> FileDifferences::getDifferences() const
{
	return differences;
}


};

