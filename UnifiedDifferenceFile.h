#ifndef DIFFERENCEPARSER_H
#define DIFFERENCEPARSER_H

#include "util.h"
#include "FileDifference.h"
#include <iostream>

namespace Waters
{

class UnifiedDifferenceFile
{
    public:
        UnifiedDifferenceFile(std::istream& istm);
        virtual ~UnifiedDifferenceFile();

        void parse();

    protected:

    private:
        std::istream& diff_stream;
        std::vector<FileDifferences> fileDiffs{};
        FileDifferences fileDiff{};

        void parseLine(const std::string& line);
};

};
#endif // DIFFERENCEPARSER_H
