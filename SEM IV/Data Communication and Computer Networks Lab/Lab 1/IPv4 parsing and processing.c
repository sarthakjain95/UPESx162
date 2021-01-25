
#include<stdio.h>

typedef unsigned char byte;
typedef struct {
	char ip_class;
	byte broadcast_address[4];
	byte netword_id[4];
	byte subnet_mask[4];
	byte address[4];
} IPv4;

byte extract_number(const char* raw_ip, const int start, const int end){
	
	byte result = 0;
	for(int i=start; i<end; i++){
		result = result * 10 + (raw_ip[i] - '0');
	}
	
	return result;
}

void parseAddress(const char* raw_input, byte* addr){

	// Only by one convert numbers in string to ip
	int last_marked_position = -1, i = 0, address_part = 0;
	while(raw_input[i] != '\0'){
		if(raw_input[i] == '.'){
			addr[address_part] = extract_number(raw_input, last_marked_position+1, i);
			last_marked_position = i;
			address_part++;
		}
		i++;
	}
	
	addr[address_part] = extract_number(raw_input, last_marked_position+1, i);
	
}

void string2IPv4(const char* raw_ip, const char* raw_subnet_mask, IPv4* ip){

	parseAddress(raw_ip, ip->address);

	// Get the location of first zero from left to right in first octet
	byte first_octet = ip->address[0];
	unsigned short first_zero = 0;
	int i = 0;
	//
	for(i=0; i<4; i++, first_zero++)
		if(!(first_octet&(0x1<<(7-i)))) 
			break;

	// Set Subnet Mask
	if(raw_subnet_mask[0] == '\0'){
		for(i=0; i<4; i++){
			if(i <= first_zero) ip->subnet_mask[i] = 255;
			else ip->subnet_mask[i] = 0;
		}
	} else {
		parseAddress(raw_subnet_mask, ip->subnet_mask);
	}

	// Set Class
	ip->ip_class = 'A' + first_zero;

	// Set network ID
	for(i=0; i<4; i++){
		ip->netword_id[i] = ip->address[i] & ip->subnet_mask[i];
	}

	// Find the broadcasting address
	for(i=0; i<4; i++){
		if(ip->subnet_mask[i] == 255){
			ip->broadcast_address[i] = ip->address[i];
		} else if(ip->subnet_mask[i] == 0) {
			ip->broadcast_address[i] = 255;
		} else{
			byte diff = 256 - ip->subnet_mask[i];
			byte octet = diff;
			while(octet < ip->address[i]) octet += diff;
			ip->broadcast_address[i] = octet - 1;
		}
	}

}

void printIPv4(const IPv4* ip){
	
	printf("IPv4: %d.%d.%d.%d \n", 
		ip->address[0], ip->address[1], ip->address[2], ip->address[3], ip->ip_class);
	
	printf("Class: '%c' \n", ip->ip_class);

	printf("Broadcasting address: %d.%d.%d.%d \n", ip->broadcast_address[0],
		ip->broadcast_address[1], ip->broadcast_address[2], ip->broadcast_address[3]);

	if(ip->ip_class == 'D')
		printf("Subnet Mask: Not Applicable (Multicast Address) \n");
	else if(ip->ip_class == 'E')
		printf("Subnet Mask: Not Applicable (Reserved) \n");
	else{
		printf("Subnet Mask: %d.%d.%d.%d \n", ip->subnet_mask[0],
			ip->subnet_mask[1], ip->subnet_mask[2], ip->subnet_mask[3]);
		printf("Network ID: %d.%d.%d.%d \n", ip->netword_id[0],
			ip->netword_id[1], ip->netword_id[2], ip->netword_id[3]);
	}	

}

int main(){

	const char* raw_ip = "172.16.20.10";
	const char* raw_subnet_mask = "255.255.240.0";
	// const char* raw_subnet_mask = "";
	// 
	IPv4 ip;
	
	string2IPv4(raw_ip, raw_subnet_mask, &ip);
	printIPv4(&ip);

	return 0;
}
