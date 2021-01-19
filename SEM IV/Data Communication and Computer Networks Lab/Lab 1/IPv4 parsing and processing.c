
#include<stdio.h>

typedef unsigned char byte;
typedef struct {
	char ip_class;
	byte netword_id[4];
	byte default_subnet_mask[4];
	byte address[4];
} IPv4;

byte extract_number(const char* ip_string, const int start, const int end){
	
	byte result = 0;
	for(int i=start; i<end; i++){
		result = result * 10 + (ip_string[i] - '0');
	}
	
	return result;
}

void string2IPv4(const char* ip_string, IPv4* ip){

	// Only by one convert numbers in string to ip
	int last_marked_position = -1, i = 0, address_part = 0;
	while(ip_string[i] != '\0'){
		if(ip_string[i] == '.'){
			ip->address[address_part] = extract_number(ip_string, last_marked_position+1, i);
			last_marked_position = i;
			address_part++;
		}
		i++;
	}
	
	ip->address[address_part] = extract_number(ip_string, last_marked_position+1, i);
	
	// Get the location of first zero from left to right in first octet
	byte first_octet = ip->address[0];
	unsigned short first_zero = 0;
	//
	for(i=0; i<4; i++, first_zero++)
		if(!(first_octet&(0x1<<(7-i)))) 
			break;

	// Set Subnet Mask
	for(i=0; i<4; i++){
		if(i <= first_zero) ip->default_subnet_mask[i] = 255;
		else ip->default_subnet_mask[i] = 0;
	}

	// Set Class
	ip->ip_class = 'A' + first_zero;

	// Set network ID
	for(int i=0; i<4; i++){
		ip->netword_id[i] = ip->address[i] & ip->default_subnet_mask[i];
	}

}

void printIPv4(const IPv4* ip){
	
	printf("IPv4: %d.%d.%d.%d \n", 
		ip->address[0], ip->address[1], ip->address[2], ip->address[3], ip->ip_class);
	
	printf("Class: '%c' \n", ip->ip_class);

	if(ip->ip_class == 'D')
		printf("Default Subnet Mask: Not Applicable (Multicast Address) \n");
	else if(ip->ip_class == 'E')
		printf("Default Subnet Mask: Not Applicable (Reserved) \n");
	else{
		printf("Default Subnet Mask: %d.%d.%d.%d \n", ip->default_subnet_mask[0],
			ip->default_subnet_mask[1], ip->default_subnet_mask[2], ip->default_subnet_mask[3]);
		printf("Network ID: %d.%d.%d.%d \n", ip->netword_id[0],
			ip->netword_id[1], ip->netword_id[2], ip->netword_id[3]);
	}	

}

int main(){

	const char* ip_string = "156.71.22.81";
	IPv4 ip;
	
	string2IPv4(ip_string, &ip);
	printIPv4(&ip);

	return 0;
}
