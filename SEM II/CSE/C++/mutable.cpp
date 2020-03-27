
#include<iostream>
using namespace std;

class classWithMutableMember{

	int coordX, coordY;
	mutable float flex;
	unsigned long id;

	public:
		classWithMutableMember(int x, int y, float f, unsigned long id){
			coordX= x;
			coordY= y;
			flex= f;
			this->id= id;
		}

		void changeFlex(float newValue) const {
			// printf("\nChanging FLEX\n(even though this is a constant function)\n");
			// printf("(but it can change flex. Coz 'flex' member is mutable.)\n");
			// printf("(but don't worry it can't change anything else.)\n");
			// printf("(*Because it's a constant function and nothing else is mutable)\n");
			// printf("(boy it is getting longer and longer)\n");
			// printf("(probably could've skipped that last line.)\n");
			// printf("(sh8 I get it n....)\n");
			printf("\nChanging Mutable Member : FLEX (via const function)\n");
			// printf("How Cool is that!\n");
			// printf("I swear I'll stop.\n");
			flex= newValue;
		}

		void printDetails(){
			printf("\nID:%lu \tX: %d,Y:%d\tFLEX:%.3f\n", id, coordX, coordY, flex);
		}
};

int main(){

	classWithMutableMember foobar(56, 90, 234.45, 0x23557456);
	foobar.printDetails();

	foobar.changeFlex(64.789);

	foobar.printDetails();

	return 0;
}
