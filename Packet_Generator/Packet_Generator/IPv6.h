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
	int flow_label;
	uint16_t payload_length;
	uint8_t next_header;
	string source_address_ipv6;
	string destination_address_ipv6;
	uint8_t ip_version;
	int traffic_class;
	uint8_t hop_limit;
	TCP* TCP_L4;
	UDP* UDP_L4;
};
#endif