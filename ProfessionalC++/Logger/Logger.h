#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <queue>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

class Logger
{
public:
	Logger();
	virtual ~Logger();
	void log(const std::string& entry);

protected:
	void processEntries();
	bool mThreadStarted;
	bool mExit;

	std::mutex mMutex;
	std::condition_variable mCondVar;
	std::queue<std::string> mQueue;
	std::thread mThread;

	std::mutex mMutexStarted;
	std::condition_variable mCondVarStarted;

private:
	Logger(const Logger& src);
	Logger& operator=(const Logger& rhs);
};

#endif
