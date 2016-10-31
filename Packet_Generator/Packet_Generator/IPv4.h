#ifndef IPv4_H
#define IPv4_H
#include <cstdint>
#include "TCP.h"
#include "UDP.h"
#include <string>


class IPv4 {
public:
	uint16_t total_length;
	TCP* TCP_L4_next_header;
	UDP* UDP_L4_next_header;
	uint32_t source_address;
	uint32_t destination_address;
	uint8_t ip_version;
	unsigned short Header_Checksum(std::string checking, unsigned size) {
		//Found an example online
		unsigned sum = 0;
		//accumulate checksum
		for (int i = 0; i < size - 1; i += 2) {
			unsigned short word16 = (unsigned short)checking[i];
			sum += word16;
			// Here to handle odd sized cases
			if (size & 1) {
				unsigned short word16 = (unsigned char)checking[i];
			}
		}
		// Here we get the ones complement
		while (sum >> 16) {
			sum = (sum & 0xFFFF) + (sum >> 16);
		}
		// we want to return the negative ones-complement
		return ~sum;
	}
};
#endif