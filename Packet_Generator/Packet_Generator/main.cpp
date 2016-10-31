#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include "Ethernet.h"
#include "IPv4.h"
#include "IPv6.h"
#include "Packet.h"
#include "TCP.h"
#include "UDP.h"
using namespace std;

Packet* Packet_Generator(int test) {
	for (int i = 0; i < test; i++) {
		Packet *protocol = new Packet();
		// Picking a random protocol from Layer 3
		if (i % 2 == 0) {
			protocol->link->data_ipv6 = new IPv6();
			protocol->link->type = 34525; //1000011011011101; This is what I found online for setting the type to IPv6
			protocol->link->source_mac = 0x1A23F9CD069B;  //Random MAC address for the source
			protocol->link->destination_mac = 0x5C66AB9075B1; //Random MAC address for the destination.
			// Picking random Layer 4 Protocol
			if (i % 2 == 0) {
				protocol->link->data_ipv6->TCP_L4_next_header = new TCP(); //IPv6 has a TCP
				protocol->link->data_ipv6->payload_length = 31;
				protocol->link->data_ipv6->TCP_L4_next_header->reserved = 0;
				protocol->link->data_ipv6->TCP_L4_next_header->data_offset = 10; //number of fields in header TCP
				protocol->link->data_ipv6->TCP_L4_next_header->source_port = 45;
				protocol->link->data_ipv6->TCP_L4_next_header->destination_port = 12;
			}
			else {
				protocol->link->data_ipv6->UDP_L4_next_header = new UDP(); //IPv6 has a UDP
				protocol->link->data_ipv6->payload_length = 31;
				protocol->link->data_ipv6->UDP_L4_next_header->destination_port_number = 40; //Random port number for destination
				protocol->link->data_ipv6->UDP_L4_next_header->source_port_number = 12;
				protocol->link->data_ipv6->UDP_L4_next_header->length = 65507; //Confused with UDP length. Could only be this because header+data= 65,535 - 8 byte - 20Byte IP header.
			}
			protocol->link->data_ipv6->ip_version = 6; // Set the version to be IPv6
			protocol->link->data_ipv6->source_address_ipv6 = "2001:0DB8:AC10:FE01:0000:0000:0000:0000"; //Random IPv6 address.
			protocol->link->data_ipv6->destination_address_ipv6 = "2001:FB01:AC10:00D1:0001:0011:0111:1111"; // Random IPv6 address.

		}
		else {
			protocol->link->data_ipv4 = new IPv4();
			protocol->link->type = 2048; //0000100000000000; This is what I found online for setting the type to IPv4 
			protocol->link->source_mac = 0x49BDD2C7562A; //Random MAC address for source.
			protocol->link->destination_mac = 0x1A49D2F9562A; //Random MAC address for Destination.
			//Picking random L4 Protocol
			if (i % 2 == 0) {
				protocol->link->data_ipv4->TCP_L4_next_header = new TCP(); // IPv4 has a TCP
				protocol->link->data_ipv4->TCP_L4_next_header->data_offset = 10; //number of fields in header TCP
				protocol->link->data_ipv4->TCP_L4_next_header->source_port = 45;
				protocol->link->data_ipv4->TCP_L4_next_header->destination_port = 12;
				protocol->link->data_ipv4->TCP_L4_next_header->check_sum = protocol->link->data_ipv4->Header_Checksum("00345e04400040063", 13); // Random packet address passed in and assigned to TCP Check_sum
			}
			else {
				protocol->link->data_ipv4->UDP_L4_next_header = new UDP(); //IPv4 has a UCP
				protocol->link->data_ipv4->UDP_L4_next_header->destination_port_number = 40; //Random port number for destination
				protocol->link->data_ipv4->UDP_L4_next_header->source_port_number = 12;
				protocol->link->data_ipv4->UDP_L4_next_header->length = 65507; //Confused looked online
				protocol->link->data_ipv4->UDP_L4_next_header->check_sum = protocol->link->data_ipv4->Header_Checksum("00345e04400040063", 13); // Random packet address passed in and assigned to TCP Check_sum
			}
			protocol->link->data_ipv4->ip_version = 4; // 4 because the type we are using is ipv4.
			protocol->link->data_ipv4->source_address = 172162541; //Random IP address for the source
			protocol->link->data_ipv4->destination_address = 1720420212; //Random IP address for the destination


		}


		return protocol;
	}


}

int main() {
	vector<Packet*> num;
	int test = 2;
	for (int j = 0; j < test; j++) {
		num.push_back(Packet_Generator(j));
	}
	for (int i = 0; i < num.size(); i++) {
		cout << "Number of packets generated is " << i + 1 << endl;
	}
}