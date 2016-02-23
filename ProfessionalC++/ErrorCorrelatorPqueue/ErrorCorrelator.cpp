#include "ErrorCorrelator.h"

using namespace std;

bool operator<(const Error& lhs, const Error& rhs)
{
	return (lhs.mPriority < rhs.mPriority);
}

ostream& operator<<(ostream& os, const Error& err)
{
	os << err.mError << " (priority " << err.mPriority << ")";
	return os;
}

void ErrorCorrelator::addError(const Error& error)
{
	mErrors.push(error);
}

Error ErrorCorrelator::getError() throw(out_of_range)
{
	if (mErrors.empty())
	{
		throw out_of_range("No more errors");
	}

	Error top = mErrors.top();
	mErrors.pop();
	return top;
}
