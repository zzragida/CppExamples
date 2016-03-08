#include "Logger.h"
#include <stdexcept>

using namespace std;

const string Logger::kLogLevelDebug = "DEBUG";
const string Logger::kLogLevelInfo = "INFO";
const string Logger::kLogLevelError = "ERROR";

const char* const Logger::kLogFileName = "log.txt";

bool Logger::sInitialized = false;
ofstream Logger::sOutputStream;

void Logger::log(const string& msg, const string& level)
{
	if (!sInitialized) {
		init();
	}
	sOutputStream << level << ": " << msg << endl;
}

void Logger::log(const vector<string>& msgs, const string& level)
{
	for (auto& msg : msgs) {
		log(msg, level);
	}
}

void Logger::teardown()
{
	if (sInitialized) {
		sOutputStream.close();
		sInitialized = false;
	}
}

void Logger::init()
{
	if (!sInitialized) {
		sOutputStream.open(kLogFileName, ios_base::app);
		if (!sOutputStream.good()) {
			throw runtime_error("Unable to initialize the Logger");
		}
		sInitialized = true;
	}
}
