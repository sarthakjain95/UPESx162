#include<cstdio>
using namespace std;

int main(){

	int x{0};
	float y{0.2};

	// More and more calculations on floating point number introduces more errors!
	y-= 0.1;
	y-= 0.1;
	y-= 0.1;
	y+= 0.1;

	if(x==y) printf("Equals! %d %.16lf\n", x, y);
	else printf("Not Equals! %d %.16lf\n", x, y);

	return 0;
}