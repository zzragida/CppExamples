#include <string>

namespace Records
{
	const int kDefaultStartingSalary = 30000;

	class Employee
	{
	public:
		Employee();

		void promote(int inRaiseAmount = 1000);
		void demote(int inDemeritAmount = 1000);
		void hire();
		void fire();
		void display() const;

		void setFirstName(std::string inFirstName);
		std::string getFirstName() const;
		void setLastName(std::string inLastName);
		std::string getLastName() const;
		void setEmployeeNumber(int inEmployeeNumber);
		int getEmployeeNumber() const;
		void setSalary(int inNewSalary);
		int getSalary() const;
		bool getIsHired() const;

	protected:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber;
		int mSalary;
		bool bHired;
	};
}
