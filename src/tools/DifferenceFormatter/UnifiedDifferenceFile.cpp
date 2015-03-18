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


void UnifiedDifferenceFile::generateHTMLReport(const std::string& leftPath, const std::string& rightPath) const
{
	ctemplate::TemplateDictionary templateDictionary("main");

	templateDictionary.SetValue("INSTRUMENT", "Velox Core TUV to Altus UV Core");
	templateDictionary.SetValue("DATE_GENERATED", util::getTime());
	
	templateDictionary.SetValue("LEFT_PATH", leftPath);
	templateDictionary.SetValue("RIGHT_PATH", rightPath);

	for (auto& diff : diffs)
	{
		auto fileDiff = std::dynamic_pointer_cast<FileDifferences>(diff);
		if (fileDiff != nullptr)
		{
			addFileDifferenceDictionary(*fileDiff, templateDictionary);
		}
		else
		{ 
			auto dirDiff = std::dynamic_pointer_cast<DirectoryDifference>(diff);
			//addDirectoryDifferenceDictionary(std::dynamic_pointer_cast<DirectoryDifference>(diff), templateDictionary);
		}
	}

	std::string report_text{};
	ctemplate::ExpandTemplate("Difference.tpl", ctemplate::DO_NOT_STRIP, &templateDictionary, &report_text);
	std::ofstream report_stm("diff_report.html");
	report_stm << report_text;
	report_stm.close();
}

void UnifiedDifferenceFile::addFileDifferenceDictionary(const FileDifferences& fileDiff, ctemplate::TemplateDictionary& dictionary) const
{
	ctemplate::TemplateDictionary *subDictionary = dictionary.AddSectionDictionary("DIFFERENCES");
	subDictionary->SetValue("DIRECTORY_DISPLAY_PROPERTY", "display: none");
	subDictionary->SetValue("FILE_DISPLAY_PROPERTY", "display: list-item");


	subDictionary->SetValue("LEFT_RELATIVE_PATH", fileDiff.leftFile().toString());
	subDictionary->SetValue("RIGHT_RELATIVE_PATH", fileDiff.rightFile().toString());


}

};



