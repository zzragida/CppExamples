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

	static Logger& instance();

	void log(const std::string& msg, const std::string& level);
	void log(const std::vector<std::string>& msgs, const std::string& level);


protected:
	static Logger sInstance;
	static const char* const kLogFileName;
	std::ofstream mOutputStream;


private:
	Logger();
	virtual ~Logger();
};
