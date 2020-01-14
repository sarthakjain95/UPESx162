
// UPESx162 - Github
// accessModifiers.cpp

#include<iostream>
#include<cstdio>
#include<ctime>

#include"containsPI.cpp"

// extern float pi;

void retain(){
	// Local static member
	static int x= 0;
	x+=2;
	printf("\nx is %d", x);
}

int main(){
	
	auto i= 0;
	for(i=0; i<4 ; i++) retain();
	
	clock_t start, stop;
	double elapsed;
	long x=0;

	size_t n= 0;
	register size_t nr= 0;

	printf("\n\nTesting to see if register variable is faster than normal variable.\n");
	printf("\n\nCounting to 2^32 using normal variable.\n");
	
	start = clock();
        for(n=0; n<4294967296; n++){
        	if(n%2 == 0) x+=n;
        	else x-=n;
        }
	stop = clock();
	elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("Normal variable took %lf seconds!\n", elapsed);
	
	printf("\n\nCounting to 2^32 using register variable.\n");
	start = clock();
        for(nr=0; nr<4294967296; nr++){
        	if(nr%2 == 0) x+=nr;
        	else x-=nr;
        }
	stop = clock();
	elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("Register variable took %lf seconds!\n", elapsed);

	printf("\nGot Pi from external file: %lf\n\n", pi );

	return 0;
}

// sarthakjain95
