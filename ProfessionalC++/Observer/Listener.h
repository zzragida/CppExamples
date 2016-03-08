#ifndef __LISTENER_H__
#define __LISTENER_H__

class Listener
{
public:
	virtual void handleMessage(int inMessage) = 0;
};

#endif
