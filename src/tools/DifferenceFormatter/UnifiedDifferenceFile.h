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
		UnifiedDifferenceFile(std::istream& istm, const std::string& leftPath, const std::string& rightPath, const std::string& header);
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

        void parseLine(const std::string& line);
		void addFileDifferenceDictionary(const FileDifferences& fileDiff, ctemplate::TemplateDictionary& dictionary) const;
		void addDirectoryDifferenceDictionary(const DirectoryDifference& dirDiff, ctemplate::TemplateDictionary& dictionary) const;
		const static std::string getRelativePathString(const Poco::Path& basePath, const Poco::File& file);
		void addDifferenceSetDictionary(const DifferenceSet& diffSet, const Poco::File& leftFile, const Poco::File& rightFile, ctemplate::TemplateDictionary *dictionary) const;
		const static std::string getCSSClassFromLineType(const Line::LineType lineType);
};

};
#endif // DIFFERENCEPARSER_H
