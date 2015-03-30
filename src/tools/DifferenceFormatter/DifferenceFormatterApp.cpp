#include "DifferenceFormatterApp.h"

namespace Waters
{

void DifferenceFormatterApp::initialize(Application& self)
{
    loadConfiguration(); // load default configuration files, if present
    Application::initialize(self);
    // add your own initialization code here
}

void DifferenceFormatterApp::uninitialize()
{
    // add your own uninitialization code here
    Application::uninitialize();
}

void DifferenceFormatterApp::reinitialize(Application& self)
{
    Application::reinitialize(self);
    // add your own reinitialization code here
}

void DifferenceFormatterApp::defineOptions(OptionSet& options)
{
    Application::defineOptions(options);

    options.addOption(
        Option("help", "h", "display help information on command line arguments")
            .required(false)
            .repeatable(false)
            .callback(OptionCallback<DifferenceFormatterApp>(this, &DifferenceFormatterApp::handleHelp)));

    options.addOption(
        Option("diff_file", "d", "bind option value to 'diff_file'")
            .required(true)
            .repeatable(false)
            .argument("file")
            .binding("diff_file"));

	options.addOption(
		Option("template", "t", "bind option value to 'template'")
			.required(true)
			.repeatable(false)
			.argument("file")
			.binding("template"));

	options.addOption(
		Option("left_path", "l", "bind option value to 'left_path'")
			.required(true)
			.repeatable(false)
			.argument("path")
			.binding("left_path"));

	options.addOption(
		Option("right_path", "r", "bind option value to 'right_path'")
			.required(true)
			.repeatable(false)
			.argument("path")
			.binding("right_path"));

	options.addOption(
		Option("header", "h", "bind option value to 'header' the header text on the difference report")
			.required(true)
			.repeatable(false)
			.argument("text")
			.binding("header"));

	options.addOption(
		Option("output_file", "o", "bind option value to 'output_file' the path and file to save the report")
		.required(true)
		.repeatable(false)
		.argument("file")
		.binding("output_file"));

	options.addOption(
		Option("context", "c", "bind option value to 'context_lines' how many lines before and after a change are included in the report")
			.required(false)
			.repeatable(false)
			.argument("lines")
			.binding("context_lines"));

}

void DifferenceFormatterApp::handleHelp(const std::string& name, const std::string& value)
{
    _helpRequested = true;
    stopOptionsProcessing();

}

void DifferenceFormatterApp::displayHelp()
{
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader("A application parses a unified format diff file.");
    helpFormatter.format(std::cout);
}

void DifferenceFormatterApp::parseDifferenceFile()
{
	std::ifstream input_stream(config().getString("diff_file"), std::ifstream::in);

	if (!input_stream.fail())
	{
		UnifiedDifferenceFile diff{input_stream, config().getString("left_path"), config().getString("right_path"), config().getString("header"), config().getString("template"), config().getString("output_file") };

		diff.parse();

		diff.generateHTMLReport();
	}
	else
	{
		std::cout << "Couldn't find the file" << std::endl;
	}
}

int DifferenceFormatterApp::main(const ArgVec& args)
{
    if (_helpRequested)
    {
        displayHelp();
    }
    else
    {
		try
		{
			parseDifferenceFile();
		}
		catch (std::exception ex)
		{
			std::cout << ex.what() << std::endl;
		}
    }

	std::cout << "Report complete. Press any key to exit.";
	std::cin.get();

    return Application::EXIT_OK;
}

void DifferenceFormatterApp::printProperties(const std::string& base)
{
    AbstractConfiguration::Keys keys;
    config().keys(base, keys);
    if (keys.empty())
    {
        if (config().hasProperty(base))
        {
            std::string msg;
            msg.append(base);
            msg.append(" = ");
            msg.append(config().getString(base));
            logger().information(msg);
        }
    }
    else
    {
        for (auto it = keys.begin(); it != keys.end(); ++it)
        {
            std::string fullKey = base;
            if (!fullKey.empty()) fullKey += '.';
            fullKey.append(*it);
            printProperties(fullKey);
        }
    }
}

};
