
// EXPERIMENT – 8

// Title: File Handling
// Objective: To understand the concept of File Handling

// 1. Write contents into a Test file. Get a word from the user as input, compute the number of
// occurrences of this word in the file and print the count.

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main(){

	const char* contents= "But I must explain to you how all this mistaken idea of denouncing pleasure and praising pain was born and I will give you a complete account of the system, and expound the actual teachings of the great explorer of the truth, the master-builder of human happiness. No one rejects, dislikes, or avoids pleasure itself, because it is pleasure, but because those who do not know how to pursue pleasure rationally encounter consequences that are extremely painful. Nor again is there anyone who loves or pursues or desires to obtain pain of itself, because it is pain, but because occasionally circumstances occur in which toil and pain can procure him some great pleasure. To take a trivial example, which of us ever undertakes laborious physical exercise, except to obtain some advantage from it? But who has any right to find fault with a man who chooses to enjoy a pleasure that has no annoying consequences, or one who avoids a pain that produces no resultant pleasure? On the other hand, we denounce with righteous indignation and dislike men who are so beguiled and demoralized by the charms of pleasure of the moment, so blinded by desire, that they cannot foresee.";
	const size_t len= strlen(contents);

	ofstream fout;
	fout.open("test.txt", ios::out);
	fout<<contents;
	fout.close();

	string word;
	printf("Enter the word you want to search:");
	cin>>word;

	string word_buffer;
	char ch;
	size_t count{};
	
	ifstream fin;
	fin.open("test.txt", ios::in);
	while(!fin.eof()){
		fin.get(ch);
		if(ch==' '){
			if( word_buffer.compare(word) == 0 ) count++;
			word_buffer= "";
		}else{
			word_buffer+=ch;
		}
	}
	if( word_buffer.compare(word) == 0 ) count++;
	fin.close();

	printf("%s was found %llu times.\n", word.c_str(), count);

	return 0;
}


