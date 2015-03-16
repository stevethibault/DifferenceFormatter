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

	std::string line{};

    while (!diff_stream.eof())
    {
		std::getline(diff_stream, line);
		parseLine(line);
	} 
}


void UnifiedDifferenceFile::parseLine(const std::string& line)
{
	if (line.substr(0, 4) == "diff")
	{
		fileDiff = std::make_shared<FileDifferences>(line);
		fileDiffs.push_back(fileDiff);
	}
    else if (line.substr(0, 4) == "--- ")
    {
        fileDiff->leftFile(line.substr(3, line.length() - 4));
    }
    else if (line.substr(0, 4) == "+++ ")
    {
        fileDiff->rightFile(line.substr(3, line.length() - 4));
    }
    else if (line.substr(0, 3) == "@@ ")
    {
        diffSet = std::make_shared<DifferenceSet>(line.substr(3, line.length() - 6));
        fileDiff->addDifferenceSet(diffSet);
    }
	else if (line[0] == '+' || line[0] == '-' || line[0] == ' ' || line.length() == 0)
    {
		diffSet->addDifference(line);
    }
}

};



