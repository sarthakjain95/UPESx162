
#include<iostream>
#include<cstdio>

using namespace std;

#define hashX 31

class typicalClassName{

	string hash;
	int hash_len;

	public:
		
		int classVarInt;
		char classVarChar;

		typicalClassName(string hx, int l){
			hash= hx;
			hash_len= l;
		}

		// void sxHash(string h, int len){hash= h;hash_len= len;}
		string gHash(){return hash;}
		// char gxHash(int x){return x>=hash_len ? '\n' : hash[x];}
};

int main(){

	typicalClassName xyz("rtwjhtrnszu", 11);
	// xyz.classVarInt= 1;
	// xyz.classVarChar= 'a';

	// (Member Function Pointer) Syntax
	// return_type (class_name::*ptr_name)=  
	string (typicalClassName::*_gx_)(void)= &typicalClassName::gHash;
	cout<<(xyz.*_gx_)()<<endl;

	return 0;
}

/* code dump
char (typicalClassName::*_cx_)(int)= &typicalClassName::gxHash;
for(int cx=0; cx<11; printf("%c",hashX+(xyz.*_cx_)(cx)), cx++);
*/