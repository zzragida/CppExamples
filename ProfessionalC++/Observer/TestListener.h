#ifndef __TEST_LISTENER_H__
#define __TEST_LISTENER_H__

#include "Listener.h"

class TestListener : public Listener
{
public:
	TestListener();
	void handleMessage(int inMessage);
	bool bMessage0Received;
	bool bUnknownMessageReceived;
};

#endif
