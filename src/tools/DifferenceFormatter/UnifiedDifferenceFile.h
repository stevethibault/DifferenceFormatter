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
        UnifiedDifferenceFile(std::istream& istm);
        virtual ~UnifiedDifferenceFile();

        void parse();
		void generateHTMLReport(const std::string& leftPath, const std::string& rightPath) const;

    protected:

    private:
        std::istream& diff_stream;
		std::vector<std::shared_ptr<Difference>> diffs{};
		std::shared_ptr<Difference> diff{};
        std::shared_ptr<DifferenceSet> diffSet{};

        void parseLine(const std::string& line);
		void addFileDifferenceDictionary(const FileDifferences& fileDiff, ctemplate::TemplateDictionary& dictionary) const;
};

};
#endif // DIFFERENCEPARSER_H
