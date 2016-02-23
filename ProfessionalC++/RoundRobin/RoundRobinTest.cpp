#include <stdexcept>
#include <iostream>
#include <string>
#include "RoundRobin.h"

using namespace std;

class Process
{
public:
	Process(const string& name) : mName(name) {}
	
	void doWorkDuringTimeSlice()
	{
		cout << "Process " << mName
				 << " performing work during time slice" << endl;
	}

	bool operator==(const Process& rhs)
	{
		return mName == rhs.mName;
	}

protected:
	string mName;
};

class Scheduler
{
public:
	Scheduler(const vector<Process>& processes);

	void scheduleTimeSlice();

	void removeProcess(const Process& process);

protected:
	RoundRobin<Process> rr;
};

Scheduler::Scheduler(const vector<Process>& processes)
{
	for (auto& process : processes)
	{
		rr.add(process);
	}
}

void Scheduler::scheduleTimeSlice()
{
	try
	{
		rr.getNext().doWorkDuringTimeSlice();
	}
	catch (const out_of_range)
	{
		cerr << "No more processes to schedule" << endl;
	}
}

void Scheduler::removeProcess(const Process& process)
{
	rr.remove(process);
}

int main()
{
	vector<Process> processes = {Process("1"), Process("2"), Process("3")};

	Scheduler sched(processes);
	for (int i = 0; i < 4; i++)
	{
		sched.scheduleTimeSlice();
	}

	sched.removeProcess(processes[1]);
	cout << "Removed second process" << endl;

	for (int i = 0; i < 4; i++)
	{
		sched.scheduleTimeSlice();
	}

	return 0;
}
