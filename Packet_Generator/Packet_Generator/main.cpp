#include <iostream>
#include <cstdint>
#include "Ethernet.h"
#include "IPv4.h"
#include "IPv6.h"
#include "Packet.h"
#include "TCP.h"
#include "UDP.h"
using namespace std;

void Packet_Generator(int test) {
	for (int i = 0; i < test; i++) {
		Packet *protocol = new Packet();
		// Picking a random protocol from Layer 3
		if (test % 2 == 0) {
			protocol->link->data_ipv6 = new IPv6();
			protocol->link->type = 1000011011011101;
			protocol->link->source_mac = 01001000000000000000000;
			
		}
		else {
			protocol->link->data = new IPv4();
			protocol->link->type = 0000100000000000;
		}

		

		//return protocol;
	}
	
	
}

int main() {
	
}