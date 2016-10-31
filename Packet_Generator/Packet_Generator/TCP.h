#ifndef TCP_H
#define TCP_H
#include <cstdint>
#include <string>

class TCP {
public:
	uint16_t source_port;
	uint16_t destination_port;
	int data_offset;
	int reserved;
	unsigned short check_sum;
};
#endif
