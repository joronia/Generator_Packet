#pragma once
#include <cstdint>
class UDP {
private:
	int source_port_number;
	int destination_port_number;
	uint64_t length;
	char checksum;
};