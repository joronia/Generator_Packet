#ifndef UDP_H
#define UDP_H
#include <cstdint>
#include <string>
class UDP {
public:
	int source_port_number;
	int destination_port_number;
	uint64_t length;
	//char checksum;
	void checksum() {

	}
};
#endif