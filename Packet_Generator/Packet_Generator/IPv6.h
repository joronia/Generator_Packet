#ifndef IPv6_H
#define IPv6_H
#pragma once
#include <cstdint>
#include <string>
#include "TCP.h"
#include "UDP.h"
using namespace std;

class IPv6 {
public:
	uint32_t payload_length;
	string source_address_ipv6;
	string destination_address_ipv6;
	uint8_t ip_version;
	TCP* TCP_L4_next_header;
	UDP* UDP_L4_next_header;
};
#endif