#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <mutex>

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
	static Logger* pInstance;
	static const char* const kLogFileName;

	std::ofstream mOutputStream;
	friend class Cleanup;
	class Cleanup
	{
	public:
		~Cleanup();
	};

	void logHelper(const std::string& msg, const std::string& level);

private:
	Logger();
	virtual ~Logger();
	Logger(const Logger&);
	Logger& operator=(const Logger&);

	static std::mutex sMutex;
};
