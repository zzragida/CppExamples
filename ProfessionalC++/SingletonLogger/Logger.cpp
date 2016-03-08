#include "Logger.h"
#include <stdexcept>

using namespace std;

const string Logger::kLogLevelDebug = "DEBUG";
const string Logger::kLogLevelInfo = "INFO";
const string Logger::kLogLevelError = "ERROR";

const char* const Logger::kLogFileName = "log.out";


Logger Logger::sInstance;

Logger& Logger::instance()
{
	return sInstance;
}

Logger::~Logger()
{
	mOutputStream.close();
}

Logger::Logger()
{
	mOutputStream.open(kLogFileName, ios_base::app);
	if (!mOutputStream.good()) {
		throw runtime_error("Unable to initialize the Logger");
	}
}

void Logger::log(const string& msg, const string& level)
{
	mOutputStream << level << ": " << msg << endl;
}

void Logger::log(const vector<string>& msgs, const string& level)
{
	for (auto& msg : msgs) {
		log(msg, level);
	}
}
