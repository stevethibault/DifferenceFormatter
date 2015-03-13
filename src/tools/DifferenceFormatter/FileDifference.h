#ifndef FILEDIFFERENCE_H
#define FILEDIFFERENCE_H

#include "DifferenceSet.h"
#include "Difference.h"
#include "Line.h"
#include "utilities.h"
#include <Poco/File.h>
#include <Poco/JSON/Object.h>
#include <Poco/Path.h>
#include <string>
#include <vector>
#include <memory>

namespace Waters
{

class FileDifferences
{
    public:
        FileDifferences() {}
        FileDifferences(const std::string& commandline);
		FileDifferences(FileDifferences &&fileDiff) : command_line(std::move(fileDiff.command_line)), left_file(std::move(fileDiff.left_file)), right_file(std::move(fileDiff.right_file)), differences(std::move(fileDiff.differences)) {}

		FileDifferences& operator=(FileDifferences&& fileDiff)
		{
			command_line = std::move(fileDiff.command_line);
			left_file = std::move(fileDiff.left_file);
			right_file = std::move(fileDiff.right_file);
			differences = std::move(fileDiff.differences);
			return *this;
		}

        static FileDifferences parse(const std::string commandline, std::istream istm);

        std::string commandLine() const;
        void commandLine(const std::string& commandline);

        Poco::Path leftFile() const;
        void leftFile(const std::string& left_file);

        Poco::Path rightFile() const;
        void rightFile(const std::string& right_file);

        void addDifferenceSet(std::shared_ptr<DifferenceSet> diffSet);

    private:
        std::string command_line{};
        Poco::Path left_file{};
        Poco::Path right_file{};
        std::vector<std::shared_ptr<DifferenceSet>> differences{};
};

}
#endif //FILEDIFFERENCE_H