#ifndef IPv4_H
#define IPv4_H
#include <cstdint>
#include "TCP.h"
#include "UDP.h"

class IPv4 {
private:
	uint8_t internet_header;
	int differentiated_service_code;
	uint16_t total_length;
	int identification;
	TCP* L4;
	UDP* sec_L4;
	uint16_t header_checksum;
	uint16_t fragment_offset;
	int time_live;
	uint32_t source_address;
	uint32_t destination_address;
	uint8_t ip_version;
};
#endif