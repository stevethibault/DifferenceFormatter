#ifndef DIFFERENCEPARSER_H
#define DIFFERENCEPARSER_H

#include "utilities.h"
#include "FileDifference.h"
#include "json_stream.h"
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
		void serializeToJSON() const;

    protected:

    private:
        std::istream& diff_stream;
		std::vector<std::shared_ptr<FileDifferences>> fileDiffs{};
		std::shared_ptr<FileDifferences> fileDiff{};
        std::shared_ptr<DifferenceSet> diffSet{};

        void parseLine(const std::string& line);
};

};
#endif // DIFFERENCEPARSER_H
