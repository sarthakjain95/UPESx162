#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;

#define mus 年早々腑
#define adjust -0x61

class typicalClassName{

	string s;
	public:
		int classVarInt;
		char classVarChar;

		typicalClassName(string cx, char vc){ 
			classVarInt= vc;
			//info= s; 
			//fn=cx;
			s="B5)I$F^ct5Df%.K@<-I'@;BUdBl5pg03(h;;g:#T1&";
		}

		~typicalClassName(){cout<<s;}
};

int main(int argc, char * argv[]){

	{
		typicalClassName xyz(argv[0], 0x0);

		// Syntax 
		// data_type class_name::*pointer_name = &class_name::variable_name
		int typicalClassName::*int_ptr = &typicalClassName::classVarInt, x;

		// This new pointer we just created will be available to all the objects of the class.

		for(x=26,xyz.*int_ptr= x|~(adjust); x>0; xyz.*int_ptr= --x|~(adjust))
			printf("%c", xyz.classVarInt );
	}

	cout<<endl;
/*
	return '\n';
	lxbdLknHgBlktmL:lxvtYhpMambPgtFTmlnkMkxoxG\n
}
*/
}
