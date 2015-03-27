#include "UnifiedDifferenceFile.h"

namespace Waters
{

	UnifiedDifferenceFile::UnifiedDifferenceFile(std::istream& istm, const std::string& leftPath, const std::string& rightPath, const std::string& header, const std::string& templateFile) 
		: diff_stream(istm), left_path(leftPath), right_path(rightPath), template_file(templateFile), report_header(header)
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
	else if (line.substr(0, 4) == "Only")
	{
		diff = std::make_shared<DirectoryDifference>(line);
		diffs.push_back(diff);
	}
    else if (line.substr(0, 4) == "--- ")
    {
		std::dynamic_pointer_cast<FileDifferences>(diff)->leftFile(line.substr(4, line.length() - 5));
    }
    else if (line.substr(0, 4) == "+++ ")
    {
		std::dynamic_pointer_cast<FileDifferences>(diff)->rightFile(line.substr(4, line.length() - 5));
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
	ctemplate::TemplateDictionary templateDictionary("main");

	templateDictionary.SetValue("HEADING", report_header);
	templateDictionary.SetValue("DATE_GENERATED", util::getTime());
	
	templateDictionary.SetValue("LEFT_PATH", left_path.toString());
	templateDictionary.SetValue("RIGHT_PATH", right_path.toString());

	for (auto& diff : diffs)
	{
		auto fileDiff = std::dynamic_pointer_cast<FileDifferences>(diff);
		if (fileDiff != nullptr)
		{
			addFileDifferenceDictionary(*fileDiff, templateDictionary);
		}
		else
		{ 
			auto dirDiff = *std::dynamic_pointer_cast<DirectoryDifference>(diff);
			addDirectoryDifferenceDictionary(dirDiff, templateDictionary);
		}
	}

	std::string report_text{};
	ctemplate::ExpandTemplate(template_file, ctemplate::DO_NOT_STRIP, &templateDictionary, &report_text);
	std::ofstream report_stm("diff_report.html");
	report_stm << report_text;
	report_stm.close();
}

void UnifiedDifferenceFile::addFileDifferenceDictionary(const FileDifferences& fileDiff, ctemplate::TemplateDictionary& dictionary) const
{
	ctemplate::TemplateDictionary *diffFileDictionary = dictionary.AddSectionDictionary("FILE_DIFFERNCE");

	diffFileDictionary->SetValue("LEFT_FILE", fileDiff.leftFile().path());
	diffFileDictionary->SetValue("RIGHT_FILE", fileDiff.rightFile().path());

	for (auto& diffSet : fileDiff.getDifferences())
	{
		addDifferenceSetDictionary(*diffSet, diffFileDictionary);
	}
}


const std::string UnifiedDifferenceFile::getRelativePathString(const Poco::Path& basePath, const Poco::File& file)
{
	std::string relativePath{};

	std::string basePathString = basePath.toString();
	std::string filePathString = file.path();

	relativePath = filePathString.substr(basePathString.length() - 1, filePathString.length() - basePathString.length() + 1);

	return relativePath;
}

void UnifiedDifferenceFile::addDifferenceSetDictionary(const DifferenceSet& diffSet, ctemplate::TemplateDictionary *dictionary) const
{
	ctemplate::TemplateDictionary *diffSetDictionary = dictionary->AddSectionDictionary("DIFFERENCE_SET");

	diffSetDictionary->SetIntValue("LEFT_STARTLINE", diffSet.leftDifference().startLine());
	diffSetDictionary->SetIntValue("LEFT_ENDLINE", diffSet.leftDifference().startLine() + diffSet.leftDifference().lineCount() - 1);
	diffSetDictionary->SetIntValue("RIGHT_STARTLINE", diffSet.rightDifference().startLine());
	diffSetDictionary->SetIntValue("RIGHT_ENDLINE", diffSet.rightDifference().startLine() + diffSet.rightDifference().lineCount() - 1);

	auto leftLines = diffSet.leftDifference().getLines();
	auto rightLines = diffSet.rightDifference().getLines();

	for (int i = 0; i < leftLines.size(); ++i)
	{
		Line left_line = leftLines[i];
		Line right_line = rightLines[i];

		ctemplate::TemplateDictionary *lineSubDictionary = diffSetDictionary->AddSectionDictionary("LINES");
		if (left_line.lineType() != Line::LineType::missing)
		{
			lineSubDictionary->SetIntValue("LEFT_LINE_NUMBER", left_line.lineNumber());
		}
		lineSubDictionary->SetValue("LEFT_LINE_CLASS", getCSSClassFromLineType(left_line.lineType()));
		lineSubDictionary->SetValue("LEFT_LINE", left_line.codeLine());

		if (right_line.lineType() != Line::LineType::missing)
		{
			lineSubDictionary->SetIntValue("RIGHT_LINE_NUMBER", right_line.lineNumber());
		}
		lineSubDictionary->SetValue("RIGHT_LINE_CLASS", getCSSClassFromLineType(right_line.lineType()));
		lineSubDictionary->SetValue("RIGHT_LINE", right_line.codeLine());
	}
}

const std::string UnifiedDifferenceFile::getCSSClassFromLineType(Line::LineType lineType)
{
	switch (lineType)
	{
	case Line::LineType::added:
		return "insert";

	case Line::LineType::removed:
		return "delete";

	case Line::LineType::unchanged:
		return "equal";

	case Line::LineType::missing:
		return "empty";

	default:
		return "";
	}
}

void UnifiedDifferenceFile::addDirectoryDifferenceDictionary(const DirectoryDifference& dirDiff, ctemplate::TemplateDictionary& dictionary) const
{
	ctemplate::TemplateDictionary *diffSetDictionary = dictionary.AddSectionDictionary("DIRECTORY_DIFFERNCE");

	diffSetDictionary->SetValue("DIR_DIFFERENCE", dirDiff.difference());
}


};



