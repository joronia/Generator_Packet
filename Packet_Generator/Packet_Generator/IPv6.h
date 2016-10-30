#pragma once
#include <cstdint>

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
};