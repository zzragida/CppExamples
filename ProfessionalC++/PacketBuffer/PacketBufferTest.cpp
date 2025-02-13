#include <iostream>
#include "PacketBuffer.h"

using namespace std;

class IPPacket
{
public:
	IPPacket(int id) : mID(id) {}
	int getID() const { return mID; }

protected:
	int mID;
};

int main()
{
	PacketBuffer<IPPacket> ipPackets(3);

	for (int i = 1; i <= 4; i++)
	{
		if (!ipPackets.bufferPacket(IPPacket(i)))
			cout << "Packet " << i << " dropped (queue is full)." << endl;
	}

	while (true)
	{
		try
		{
			IPPacket packet = ipPackets.getNextPacket();
			cout << "Processing packet " << packet.getID() << endl;
		}
		catch (const out_of_range)
		{
			cout << "Queue is empty" << endl;
			break;
		}
	}

	return 0;
}
