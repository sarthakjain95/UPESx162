
#include<iostream>
#include<fstream>
using namespace std;


int main(int argc, char * argv[]){

	if(argc<2){

		printf("\n256-bit Hash Generator\n");
		printf("\n:USAGE:\n>./[executable binary] [filename]");
		printf("\n\nDoing this will return a [32 Character] String of AlphaNumeric Characters.");
		printf("\nExample: xxgo7gxoec830wacyqhmgfwn087og7x1");
		// :Try Running:
		// >./a.out ./a.out
		printf("\n\nWhen you want to check the integrity of a file, just compare the two hashValues.\n");

	}else{

		const char * mapping= "1234567890qwertyuiopasdfghjklzxcvbnm";
		const short MAX= 36;
		
		char hashValues[32];
		unsigned short pos= 0;

		char ch;
		unsigned int res= 0;
		ifstream fin(argv[1]);
		fin.seekg(0, ios::beg);

		if(!fin){
			printf(":ERROR:");
			printf("\nCould not open file!\n");
			return -1;
		}

		while(!fin.eof()){
		    fin.get(ch);
		    if( pos==0 ) res= hashValues[pos]+ ch;
		    else res= hashValues[pos] + hashValues[pos-1] + ch;
		    pos= (pos+1)%32;
		    hashValues[pos]= res%MAX;
		}

		string finalHash= "";
		for(int x=0; x<32; x++) finalHash+= mapping[ hashValues[x] ];

		cout<<"Generated Hash is: "<<finalHash;

	}

	cout<<endl;
	return 0;
}

