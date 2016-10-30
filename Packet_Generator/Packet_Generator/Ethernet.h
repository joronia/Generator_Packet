#pragma once
#include <cstdint>

class Ethernet {
private:
	uint64_t source_mac;
	uint64_t destination_mac;
	uint64_t preamble;
	uint16_t type;
	//data
	uint32_t fcs;
};