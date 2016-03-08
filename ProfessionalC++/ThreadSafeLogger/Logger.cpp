#include "Logger.h"
#include <stdexcept>

using namespace std;

const string Logger::kLogLevelDebug = "DEBUG";
const string Logger::kLogLevelInfo = "INFO";
const string Logger::kLogLevelError = "ERROR";

const char* const Logger::kLogFileName = "log.txt";

Logger* Logger::pInstance = nullptr;

mutex Logger::sMutex;

Logger& Logger::instance()
{
	static Cleanup cleanup;

	lock_guard<mutex> guard(sMutex);
	if (pInstance == nullptr)
		pInstance = new Logger();
	return *pInstance;
}

Logger::Cleanup::~Cleanup()
{
	lock_guard<mutex> guard(Logger::sMutex);
	delete Logger::pInstance;
	Logger::pInstance = nullptr;
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
	lock_guard<mutex> guard(sMutex);
	logHelper(msg, level);
}

void Logger::log(const vector<string>& msgs, const string& level)
{
	lock_guard<mutex> guard(sMutex);
	for (auto& msg : msgs) {
		logHelper(msg, level);
	}
}

void Logger::logHelper(const string& msg, const string& level)
{
	mOutputStream << level << ": " << msg << endl;
}
