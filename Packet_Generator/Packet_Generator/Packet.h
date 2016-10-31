#ifndef Packet_H
#define Packet_H
#include "Ethernet.h"
#include <string>

class Packet {
public:
	Ethernet* link = new Ethernet();
};
#endif