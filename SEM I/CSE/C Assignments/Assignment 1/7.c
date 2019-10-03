
#include<stdio.h>

// Q.WAP to find the biggest of 3 numbers.

int main(int argc, char * argv[]){
	
	int l,m,n;
	printf("\nEnter Three Numbers:");
	scanf("%d%d%d",&l,&m,&n);

	int biggest=0;
	biggest= l>n ? ( l>m ? l : m ) : ( n>m ? n : m );
	printf("\nBiggest Number is %d\n",biggest);

	return 0;
}
