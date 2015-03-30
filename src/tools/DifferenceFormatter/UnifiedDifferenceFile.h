#ifndef DIFFERENCEPARSER_H
#define DIFFERENCEPARSER_H

#include "utilities.h"
#include "ctemplate\template.h"
#include "Difference.h"
#include "FileDifference.h"
#include "DirectoryDifference.h"
#include <iostream>
#include <fstream>
#include <memory>

namespace Waters
{

class UnifiedDifferenceFile
{
    public:
		UnifiedDifferenceFile(std::istream& istm, const std::string& leftPath, const std::string& rightPath, const std::string& header, const std::string& templateFile, const std::string outputFile)
			: diff_stream(istm), left_path(leftPath), right_path(rightPath), report_header(header), template_file(templateFile), output_file(outputFile)
		{}

        virtual ~UnifiedDifferenceFile();

        void parse();
		void generateHTMLReport() const;

    protected:

    private:
        std::istream& diff_stream;
		std::vector<std::shared_ptr<Difference>> diffs{};
		std::shared_ptr<Difference> diff{};
        std::shared_ptr<DifferenceSet> diffSet{};
		Poco::Path left_path{};
		Poco::Path right_path{};
		std::string report_header{};
		std::string template_file{};
		std::string output_file{};

        void parseLine(const std::string& line);
		void addFileDifferenceDictionary(const FileDifferences& fileDiff, ctemplate::TemplateDictionary& dictionary) const;
		void addDirectoryDifferenceDictionary(const DirectoryDifference& dirDiff, ctemplate::TemplateDictionary& dictionary) const;
		const static std::string getRelativePathString(const Poco::Path& basePath, const Poco::File& file);
		void addDifferenceSetDictionary(const DifferenceSet& diffSet, ctemplate::TemplateDictionary *dictionary) const;
		const static std::string getCSSClassFromLineType(const Line::LineType lineType);
};

};
#endif // DIFFERENCEPARSER_H
