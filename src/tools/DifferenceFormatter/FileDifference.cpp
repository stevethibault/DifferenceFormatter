#include "FileDifference.h"

namespace Waters
{

FileDifferences::FileDifferences(const std::string& input_line) :
    line(input_line)
{

}

std::string FileDifferences::commandLine() const
{
    return line;
}

void FileDifferences::commandLine(const std::string& command)
{
    line = command;
}

Poco::File FileDifferences::leftFile() const
{
    return left_file;
}

void FileDifferences::leftFile(const std::string& left)
{
	std::vector<std::string> fileAndTime = util::split(left, std::string{"\t"});

    left_file = Poco::File(fileAndTime[0]);
	left_file_ts = FileDifferences::getTimestamp(fileAndTime[1]);
}

Poco::File FileDifferences::rightFile() const
{
    return right_file;
}

void FileDifferences::rightFile(const std::string& right)
{
	std::vector<std::string> fileAndTime = util::split(right, std::string{"\t"});

	right_file = Poco::File(fileAndTime[0]);
	right_file_ts = FileDifferences::getTimestamp(fileAndTime[1]);
}

void FileDifferences::addDifferenceSet(std::shared_ptr<DifferenceSet> diffSet)
{
    differences.push_back(diffSet);
}

const std::vector<std::shared_ptr<DifferenceSet>> FileDifferences::getDifferences() const
{
	return differences;
}

Poco::Timestamp FileDifferences::getTimestamp(std::string dateTimeAndZone)
{
	int timeZoneStart = dateTimeAndZone.find_last_of('-');
	int timeZoneOffset = std::atoi(dateTimeAndZone.substr(timeZoneStart, dateTimeAndZone.length() - timeZoneStart).c_str());
	std::string dateTime = dateTimeAndZone.substr(0, timeZoneStart - 1);

	Poco::Timestamp timeStamp = Poco::DateTimeParser::parse("%Y-%m-%d %H:%M:%s", dateTime, timeZoneOffset).timestamp();

	return timeStamp;
		//2011-06-16 16:28:22.000000000 -040
}

};

