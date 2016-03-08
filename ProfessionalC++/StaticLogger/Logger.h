#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Logger
{
public:
	static const std::string kLogLevelDebug;
	static const std::string kLogLevelInfo;
	static const std::string kLogLevelError;

	static void log(const std::string& msg, const std::string& level);
	static void log(const std::vector<std::string>& msgs, const std::string& level);
	static void teardown();
	
protected:
	static void init();
	static const char* const kLogFileName;
	static bool sInitialized;
	static std::ofstream sOutputStream;

private:
	Logger() {}
};
