#ifndef Ethernet_H
#define Ethernet_H
#include <cstdint>
#include "IPv4.h"
#include "IPv6.h"

class Ethernet {
public:
	 uint64_t source_mac;
	uint64_t destination_mac;
	uint64_t preamble;
	uint16_t type;
	IPv4* data;
	IPv6* data_ipv6;
	void CRC() {

	}
};
#endif