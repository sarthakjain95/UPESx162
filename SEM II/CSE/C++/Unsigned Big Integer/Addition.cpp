#include<iostream>
#include <bitset>
#include <stdexcept>

using namespace std;

#define MAX 16

// :Limitations:
// Initialization should start with a size type value
// No base-10 Representation Present in this Version

class UnsignedBigInteger{

	uint8_t num[MAX];

	public:

		UnsignedBigInteger(){ clear(); }

		UnsignedBigInteger(size_t x){

			clear();
			uint8_t y;

			for(int i=0; i<sizeof(x); i++){
				y= 0b00000000;
				for(int k=0; k<8; k++){
					// cout<<(x>>(k+8*i))<<endl;
					if( x>>(k+8*i)&0x1 ) y+= 0x1<<k;
				}
				// cout<< bitset<8>(y) << endl;
				num[MAX-i-1]= y;
			}

		}

		UnsignedBigInteger(const UnsignedBigInteger& x){

			clear();
			for(int i=0; i<MAX; i++){
				this->num[i]= x.num[i];
			}

		}

		void operator=(UnsignedBigInteger n){
			clear();
			for(int i=0; i<MAX; i++){
				this->num[i]= n.num[i];
			}
		}

		void clear(){
			for(int i=0; i<MAX; i++) num[i]= 0;
		}

		void print(uint8_t x=0){

			// size_t res= 0;
			// for(int i=MAX-1; i>=0; i--){
			// 	for(int k=0; k<8; k++){
			// 		if( (num[i]>>k) & 0x1 ){
			// 			res+= (0x1<<(((MAX-1-i)*8) + k));
			// 		}
			// 	}
			// }
			// cout<< "UnsignedBigInteger Value:" << res << endl;
			
			// if(x){
				for(int i=0; i<MAX; i++){
					cout<< bitset<8>(num[i]);
				}
				cout<<endl;
			// }

		}

		void addByte(bitset<8> byte, int8_t pos){
			
			if( pos<0 ){
				throw runtime_error{ "Overflow in UnsignedBigInteger!" };
			}

			if( (byte.to_ulong()+num[pos]) > 255 ){
			
				uint16_t twoBytes= (byte.to_ulong()+num[pos]);
				bitset<8> parts[2];
			
				for(unsigned short i=0; i<16; i++){
					if( (twoBytes>>i)&0x1 ){
						// parts[i/8]+= 0x1<<(i%8);
						parts[i/8].set(i%8);
					}
				}
			
				num[pos]= parts[0].to_ulong();
				addByte(parts[1],pos-1);
			
			}else{
				num[pos]+= byte.to_ulong();
			}

		}

		UnsignedBigInteger operator+(size_t x){

			UnsignedBigInteger result{*this};
			result+= x;

			return result;

		}

		void operator+=(size_t x){

			// printf("Adding %lu to UnsignedBigInteger\n", x);

			uint8_t i=0;
			bitset<8> byte= 0;
			
			for(; i<sizeof(x); i++){
				byte.set().flip();
				for(uint8_t k=0; k<8; k++){
					// if( (x>>(8*i + k))&0x1 ) byte|=0x1<<k;
					if( (x>>(8*i + k))&0x1 ) byte.set(k);
				}
				// cout<< bitset<8>(byte) << " " << i << " " << MAX-i-1 << endl;
				if(byte.to_ulong()) addByte(byte, MAX-i-1);
			}

			return;
		}

		UnsignedBigInteger operator+(UnsignedBigInteger x){
			for(int i=0; i<MAX; i++){
				addByte( x.num[i], i );
			}
			// print();
			return *this;
		}

};

int main(){
	
	UnsignedBigInteger x{224235};
	x.print();

	UnsignedBigInteger y= x+3445634;
	y.print();

	UnsignedBigInteger z= x + y;
	z.print();

	cout<<endl;
	return 0;
}
