
// UPESx162 - Github
// storageClassSpecifiers.cpp

#include<iostream>
#include<cstdio>

// using namespace std; 

typedef __int128_t d128;
typedef std::string string;

class hash{

	// Private by default
	string color2hash(string color){ return "GLL`C!S`"; }

	int _hX_dlim_(d128 face, int x=0xf, char c='F'){
		return printf("%c", (((face&0x1FULL<<x*5)>>x*5)+0x40) );
	}

	protected:

		d128 color;
		void hash2color(d128 hs, int i=0){ for(;i<8;i++) _hX_dlim_(hs, i); }

	public:

		// Seriously though, who needs this?
		string description;
		hash(){ color=0xfbde6fc822; }

};

class hashInterface : private hash {

	d128 face;
	int dx;

	public:

		void setColor(d128 c){ color= c; }

		string getHash(){ hash2color(face); return " "; }
		hashInterface(d128 f, int ex){ face= f; }

};

int main(){

	hashInterface x_17(0xfc822FBDE6,8);
	std::cout<<x_17.getHash()<<std::endl;
	return 0;

}

// sarthakjain95
