#ifndef Ethernet_H
#define Ethernet_H
#include <cstdint>
#include <string>
#include "IPv4.h"
#include "IPv6.h"

class Ethernet {
public:
	uint64_t source_mac;
	uint64_t destination_mac;
	uint16_t type;
	IPv4* data_ipv4;
	IPv6* data_ipv6;
};
#endif