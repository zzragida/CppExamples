#include "Logger.h"
#include <fstream>
#include <iostream>

using namespace std;

Logger::Logger() : mThreadStarted(false), mExit(false)
{
	mThread = thread{&Logger::processEntries, this};
	unique_lock<mutex> lock(mMutexStarted);
	mCondVarStarted.wait(lock, [&](){return mThreadStarted == true;});
}

Logger::~Logger()
{
	mExit = true;
	mCondVar.notify_all();
	mThread.join();
}

void Logger::log(const string& entry)
{
	unique_lock<mutex> lock(mMutex);
	mQueue.push(entry);
	mCondVar.notify_all();
}

void Logger::processEntries()
{
	ofstream ofs("log.txt");
	if (ofs.fail()) {
		cerr << "Failed to open logfile" << endl;
		return;
	}

	unique_lock<mutex> lock(mMutex);
	mThreadStarted = true;
	mCondVarStarted.notify_all();

	while (true) {
		mCondVar.wait(lock);
		lock.unlock();

		while (true) {
			lock.lock();
			if (mQueue.empty()) {
				break;
			} else {
				ofs << mQueue.front() << endl;
				mQueue.pop();
			}
			lock.unlock();
		}

		if (mExit)
			break;
	}
}
