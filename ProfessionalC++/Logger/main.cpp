#include "Logger.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

using namespace std;

void logSomeMessages(int id, Logger& logger)
{
	for (int i = 0; i < 10; ++i) {
		stringstream ss;
		ss << "Log entry " << i << " from thread" << id;
		logger.log(ss.str());
	}
}

int main()
{
	Logger logger;

	vector<thread> threads;

	for (int i = 0; i < 10; ++i) {
		threads.push_back(thread{logSomeMessages, i, ref(logger)});
	}

	for (auto& t : threads) {
		t.join();
	}

	return 0;
}
