#ifndef DIFFERENCEPARSERAPP_H
#define DIFFERENCEPARSERAPP_H

#include "UnifiedDifferenceFile.h"
#include <Poco/Util/Application.h>
#include <Poco/Util/Option.h>
#include <Poco/Util/OptionSet.h>
#include <Poco/Util/HelpFormatter.h>
#include <Poco/Util/AbstractConfiguration.h>
#include <Poco/AutoPtr.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace Poco;
using namespace Poco::Util;

namespace Waters
{

class DifferenceFormatterApp: public Application
{
public:

	DifferenceFormatterApp(): _helpRequested(false)
	{}

protected:

	void initialize(Application& self);

	void uninitialize();

	void reinitialize(Application& self);

	void defineOptions(OptionSet& options);

	void handleHelp(const std::string& name, const std::string& value);

	void displayHelp();

	int main(const ArgVec& args);

	void printProperties(const std::string& base);

private:
	bool _helpRequested;

    void parseDifferenceFile();
};

};
#endif // DIFFERENCEPARSERAPP_H

