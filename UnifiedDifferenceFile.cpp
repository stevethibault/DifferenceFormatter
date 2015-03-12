#include "UnifiedDifferenceFile.h"

namespace Waters
{

UnifiedDifferenceFile::UnifiedDifferenceFile(std::istream& istm) : diff_stream{istm}
{
    //ctor
}

UnifiedDifferenceFile::~UnifiedDifferenceFile()
{
    //dtor
}


void UnifiedDifferenceFile::parse()
{
    while (!diff_stream.eof())
    {
        std::string line{};
        std::getline(diff_stream, line);
        parseLine(line);
    }
}


void UnifiedDifferenceFile::parseLine(const std::string& line)
{
    if (line.substr(0, 4) == "diff")
    {
        fileDiff = FileDifferences(line);
    }
    else if (line.substr(0, 4) == "--- ")
    {
        fileDiff.leftFile(line.substr(3, line.length() - 4));
    }
    else if (line.substr(0, 4) == "+++ ")
    {
        fileDiff.leftFile(line.substr(3, line.length() - 4));
    }
    else if (line.substr(0, 3) == "@@ ")
    {
        diffSet = DifferenceSet(line.substr(2, line.length() - 6));
        fileDiff.addDifferenceSet(diffSet);
    }
    else if (line[0] == ' ' || line.length() == 0)
    {
        diffSet.addDifference(line, Line::LineType::unchanged);
    }
}

};



