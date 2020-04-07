#include<iostream>
#include<functional>
using namespace std;

// Follows Open Addressing
template<class Fn>
struct HashTable{

	uint64_t * table;
	const size_t size;
	Fn hashCalculator;

	HashTable(size_t size, Fn func) : size{size} {
		hashCalculator= func;
		table= new uint64_t[size];
		for(size_t i{}; i<size; i++) table[i]= 0;
	}

	int64_t insert(size_t val){
		size_t pos= hashCalculator(val);
		if( pos>=size ){
			return -1;
		}else{
			if( table[pos] ){
				size_t i{ (pos+1)%size };
				while(table[i]!=0 && i!=pos) i= (i+1)%size;
				if(i==pos) return -1;
				table[i]= val;
				return i;
			}else{
				table[pos]= val;
				return pos;
			}
		}
	}

	size_t check(uint64_t val){
		size_t pos= hashCalculator(val);
		if( pos>=size ){
			return false;
		}else{
			if( table[pos]!=val ){
				size_t i{ (pos+1)%size };
				while(table[i]!=val && i!=pos) i= (i+1)%size;
				if(i==pos) return false;
				else return i;
			}else{
				return pos;
			}
		}		
	}

	void del(uint64_t val){
		size_t pos= check(val);
		if( table[pos]==val ){ 
			table[pos]= 0;
			printf("%llu Deleted.\n", val);
		}else{
			printf("%llu not found!\n", val);
		}	
	}

	void print(){
		cout<<endl;
		for(size_t i{}; i<size; i++) 
			if(table[i]) printf("%llu ", table[i]); 
		cout<<endl;
	}

};

int main(){

	size_t size{200};
	// printf("Enter Size for Hash Table:");
	// scanf("%llu", &size);
	printf("Hash Table size is %llu\n", size);

	HashTable <function<size_t(size_t)>>db(size, [=](size_t val){ return val%size; });

	size_t temp{};
	uint8_t ans{};
	while(true){

		printf("\nSelect one of the choices:\n");
		printf("1. Enter a Element\n2. Check Element\n3. Delete Element\n4. Print Table");
		printf("\n5. Exit\n");
		printf("Enter>>");
		scanf("%d", &ans);
		
		switch(ans){

			case 1:{
					printf("\nEnter new (Positive) Value:");
					scanf("%llu", &temp);
					if( db.insert(temp) == -1 ) printf("Error Occured!\nCould not insert new Value!\n");
					else printf("Added Value!\n"); 
			} break;

			case 2:{
					printf("\nEnter Value to Check:");
					scanf("%llu", &temp);
					temp= db.check(temp);
					if( temp == false ) printf("Element not found!\n");
					else printf("Element found at %llu!\n", temp);
			} break;

			case 3:{
					printf("\nEnter value to be deleted:");
					scanf("%llu", &temp);
					db.del(temp);
			} break;

			case 4:{
					db.print();
			} break;

			case 5:{
					return 0;
			} break;

			default:{
					printf("\nInvalid Choice. Try Again!\n");
			}
		}
	
	}

}