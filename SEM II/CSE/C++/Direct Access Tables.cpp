#include<iostream>
using namespace std;

int main(){

	size_t size{};
	printf("Enter the size of Direct Acces Table: ");
	cin>>size;

	uint8_t dat[size];

	for(uint8_t i{}; i<size; i++) dat[i]= 0;

	char ans= 1;
	while(true){

		printf("\nDo you want to add new Element? (y/n): ");
		cin>>ans;

		if(ans=='y'){

			size_t elem;
			printf("Enter New Element:");
			cin>>elem;

			if( elem>=size ){
				printf("Cannot add element that is bigger than Table!\n");
			}else{
				dat[elem]= 1;
				printf("Added!\n");
			}

		}else if(ans=='n'){ break; }
		else{ printf("Invalid Response!\n"); }

	}

	printf("\n:Printing Table:\n");

	for(size_t i{}; i<size; i++){
		if( dat[i] ) printf("%llu ", i);
	}

	cout<<endl;
	return 0;

}