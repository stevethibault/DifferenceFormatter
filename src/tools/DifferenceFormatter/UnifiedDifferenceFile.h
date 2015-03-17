#ifndef DIFFERENCEPARSER_H
#define DIFFERENCEPARSER_H

#include "utilities.h"
#include "ctemplate\template.h"
#include "Difference.h"
#include "FileDifference.h"
#include "DirectoryDifference.h"
#include <iostream>
#include <memory>

namespace Waters
{

class UnifiedDifferenceFile
{
    public:
        UnifiedDifferenceFile(std::istream& istm);
        virtual ~UnifiedDifferenceFile();

        void parse();
		void generateHTMLReport() const;

    protected:

    private:
        std::istream& diff_stream;
		std::vector<std::shared_ptr<Difference>> diffs{};
		std::shared_ptr<Difference> diff{};
        std::shared_ptr<DifferenceSet> diffSet{};

        void parseLine(const std::string& line);
};

};
#endif // DIFFERENCEPARSER_H
