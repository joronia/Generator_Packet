#ifndef TCP_H
#define TCP_H
#include <cstdint>
#include <string>

class TCP {
public:
	uint16_t source_port;
	uint16_t destination_port;
	//uint32_t sequence_number; //random
	//uint32_t anknow_num; //random
	int data_offset; 
	int reserved;
	//char flags; //random
	//uint16_t windows_size;
	uint16_t check_sum;
	//uint16_t urgent_pointer; //random
};
#endif
