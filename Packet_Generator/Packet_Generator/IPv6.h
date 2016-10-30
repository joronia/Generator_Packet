#ifndef IPv6_H
#define IPv6_H
#include <cstdint>
#include "TCP.h"
#include "UDP.h"

class IPv6 {
private:
	int flow_label;
	uint16_t payload_length;
	uint8_t next_header;
	char source_address;
	char destination_address;
	uint8_t ip_version;
	int traffic_class;
	uint8_t hop_limit;
	TCP* L4;
	UDP* sec_L4;
};
#endif