#ifndef IPv4_H
#define IPv4_H
#include <cstdint>
#include "TCP.h"
#include "UDP.h"
#include <string>


class IPv4 {
public:
	//uint8_t internet_header;
	//string differentiated_service_code;
	uint16_t total_length;
	//int identification;
	TCP* TCP_L4;
	UDP* UDP_L4;
	uint16_t header_checksum;
	//uint16_t fragment_offset;
	//int time_live;
	uint32_t source_address;
	uint32_t destination_address;
	uint8_t ip_version;
};
#endif