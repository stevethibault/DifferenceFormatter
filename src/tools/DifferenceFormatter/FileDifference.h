#ifndef FILEDIFFERENCE_H
#define FILEDIFFERENCE_H

#include "Difference.h"
#include "DifferenceSet.h"
#include "DifferenceChunk.h"
#include "Line.h"
#include "utilities.h"
#include <Poco/File.h>
#include <Poco/JSON/Object.h>
#include <Poco/Path.h>
#include <string>
#include <vector>
#include <memory>
#include <ctime>

namespace Waters
{

class FileDifferences : public Difference
{
    public:
        FileDifferences() {}
        FileDifferences(const std::string& line);
		FileDifferences(FileDifferences &&fileDiff) : line(std::move(fileDiff.line)), left_file(std::move(fileDiff.left_file)), right_file(std::move(fileDiff.right_file)), differences(std::move(fileDiff.differences)) {}

		FileDifferences& operator=(FileDifferences&& fileDiff)
		{
			line = std::move(fileDiff.line);
			left_file = std::move(fileDiff.left_file);
			right_file = std::move(fileDiff.right_file);
			differences = std::move(fileDiff.differences);
			return *this;
		}

        static FileDifferences parse(const std::string commandline, std::istream istm);

        std::string commandLine() const;
        void commandLine(const std::string& commandline);

        Poco::File leftFile() const;
        void leftFile(const std::string& left_file);

        Poco::File rightFile() const;
        void rightFile(const std::string& right_file);

        void addDifferenceSet(std::shared_ptr<DifferenceSet> diffSet);

		const std::vector<std::shared_ptr<DifferenceSet>> getDifferences() const;


    private:
		std::string line{};
        Poco::File left_file{};
		Poco::Timestamp left_file_ts{};
        Poco::File right_file{};
		Poco::Timestamp right_file_ts{};
        std::vector<std::shared_ptr<DifferenceSet>> differences{};
		static Poco::Timestamp getTimestamp(std::string dateTimeAndZone);
};

}
#endif //FILEDIFFERENCE_H
