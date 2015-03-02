#include "DifferenceFormatterApp.h"

void initialize(Application& self)
{
    loadConfiguration(); // load default configuration files, if present
    Application::initialize(self);
    // add your own initialization code here
}

void uninitialize()
{
    // add your own uninitialization code here
    Application::uninitialize();
}

void reinitialize(Application& self)
{
    Application::reinitialize(self);
    // add your own reinitialization code here
}

void defineOptions(OptionSet& options)
{
    Application::defineOptions(options);

    options.addOption(
        Option("help", "h", "display help information on command line arguments")
            .required(true))
            .repeatable(false)
            .binding("test.property"));

    options.addOption(
        Option("patchfile", "p", "Specify the old path, or left compare path")
            .required(true)
            .repeatable(false)
            .argument("file")
            .binding("patchfile"));

}


void displayHelp()
{
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader("An application that parces unified format diff or patch files.");
    helpFormatter.format(std::cout);
}


int main(const ArgVec& args)
{
    if (!_helpRequested)
    {
        logger().information("Command line:");
        std::ostringstream ostr;
        for (ArgVec::const_iterator it = argv().begin(); it != argv().end(); ++it)
        {
            ostr << *it << ' ';
        }
        logger().information(ostr.str());
        logger().information("Arguments to main():");
        for (ArgVec::const_iterator it = args.begin(); it != args.end(); ++it)
        {
            logger().information(*it);
        }
        logger().information("Application properties:");
        printProperties("");
    }
    return Application::EXIT_OK;
}

void printProperties(const std::string& base)
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
        for (AbstractConfiguration::Keys::const_iterator it = keys.begin(); it != keys.end(); ++it)
        {
            std::string fullKey = base;
            if (!fullKey.empty()) fullKey += '.';
            fullKey.append(*it);
            printProperties(fullKey);
        }
    }
}
