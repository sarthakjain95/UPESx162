#include<iostream>
using namespace std;

#define const_length 64

string get_random_string(){
	string s{""};
	char c{};
	int w100{};
	for(int i{}; i<const_length; i++){
		w100= (rand()%100);
		if( w100 < 33 ) c= 65 + rand()%26;
		else if( w100 < 66 ) c= 48 + rand()%10;
		else c= 97 + rand()%26;
		s+= c;
	}
	return s;
}

int main(){

	while(1){
		for(int i=0; i<const_length; i++) cout<<"\b";
		cout<< get_random_string() << flush;
	}

	return 0;
}