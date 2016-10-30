#pragma once
#include <cstdint>

class TCP {
private:
	uint16_t source_port;
	uint16_t destination_port;
	uint32_t sequence_number;
	uint32_t anknow_num;
	char data_offset;
	char reserved;
	char flags;
	uint16_t windows_size;
	uint16_t check_sum;
	uint16_t urgent_pointer;
};
