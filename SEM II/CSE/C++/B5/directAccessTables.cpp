
#include<iostream>
#include<random>
#include<ctime>
using namespace std;

// Recommended Read: https://web.stanford.edu/class/archive/cs/cs161/cs161.1168/lecture9.pdf

int main(){

	srand((unsigned)time(0)); 

	unsigned int max= 0;
	printf("\nEnter Max limit for the Table: ");
	cin>>max;

	int arr[max];
	printf("Created Table for %d elements.\n", max);

	for(int d=0; d<max; d++) arr[d]= -1;

	unsigned int chosenIndex= 0;
	unsigned short choice= 0;
	while(1){

		cout<<"\nChoose a number between: 0 to "<<max<<" :";
		cin>>chosenIndex;

		if( chosenIndex > max ){
			printf("\nInvalid Number Chosen.");
			chosenIndex= (rand()%(max-1));
			printf("\nRandomly Chosen %d", chosenIndex);
		}

		printf("\n\nChoose one of the following options:");
		printf("\n1.Delete\n2.Add");
		// printf("\n3.Destroy this universe");
		// printf("\n3.Why am I doing this again?");
		printf("\n3.Check\n4.Beam me up scotty!");
		cout<<"\nEnter:";
		cin>>choice;

		switch(choice){
			case 1:{
					arr[chosenIndex]= -1;
					printf("%d no longer exists.", chosenIndex);
			} break;

			case 2:{
					arr[chosenIndex]= chosenIndex;
					printf("\nAdded %d.", chosenIndex);
			} break;

			case 3:{
					if(arr[chosenIndex]!=-1){
						printf("\n%d Exists.", chosenIndex);
					}else{
						printf("\n%d Does not Exist.", chosenIndex);
					}
			} break;

			// case 3:{
			// 	if(1) delete universe;
			// } break;

			case 4:{
					return 0;
			} break;

			default:{
				// printf("\nLet me guess Dyslexia?");
				// printf("\nAre you having a stroke?");
				printf("\nInvalid Selection.");
			}
		}

	}

	return 0;
}
