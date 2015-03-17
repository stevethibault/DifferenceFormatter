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
		diff = std::make_shared<FileDifferences>(line);
		diffs.push_back(diff);
	}
	else if (line.substr(0, 5) == "Only")
	{
		diff = std::make_shared<DirectoryDifference>(line);
		diffs.push_back(diff);
	}
    else if (line.substr(0, 4) == "--- ")
    {
		std::dynamic_pointer_cast<FileDifferences>(diff)->leftFile(line.substr(3, line.length() - 4));
    }
    else if (line.substr(0, 4) == "+++ ")
    {
		std::dynamic_pointer_cast<FileDifferences>(diff)->rightFile(line.substr(3, line.length() - 4));
    }
    else if (line.substr(0, 3) == "@@ ")
    {
        diffSet = std::make_shared<DifferenceSet>(line.substr(3, line.length() - 6));
		std::dynamic_pointer_cast<FileDifferences>(diff)->addDifferenceSet(diffSet);
    }
	else if (line[0] == '+' || line[0] == '-' || line[0] == ' ' || line.length() == 0)
    {
		diffSet->addDifference(line);
    }
}


void UnifiedDifferenceFile::generateHTMLReport() const
{
	
}

};



