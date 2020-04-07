// EXPERIMENT – 10

// Title: Hash tables
// Objective: To understand the concepts of Hash tables

// 3. Repeat S.No.2 with Linear probing as Collision avoidance strategy.

#include<iostream>
#include<exception>
using namespace std;

#define FAMILY_LENGTH 10

class ChainLengthException: public exception{

	public:
		const char * what() const throw(){
			return "Chain Length Exceeded!\n";
		}

};

class HashTable{

	unsigned long table[FAMILY_LENGTH];

public:
	HashTable(){
		for(long i{}; i<FAMILY_LENGTH; i++) 
			table[i]= 0;
	}

	unsigned long get_hash(unsigned long sap) const {
		unsigned long sum{sap%1000};
		while(sum>9) sum-=9;
		return sum;
	}

	long search(unsigned long sap) const {
		unsigned long i= get_hash(sap);
		if(table[i]==sap){
			return i;
		}else{
			unsigned long j= (i+1)%FAMILY_LENGTH;
			while(j!=i && table[j]!=sap) j= (j+1)%FAMILY_LENGTH; 
			if(i!=j) return j;
			else return -1;
		}
	}

	void insert(unsigned long sap){
		unsigned long i= get_hash(sap);
		if(table[i]==0){
			table[i]= sap;
		}else{
			unsigned long j=i+1;
			while(j!=i && table[j]!=0) j= (j+1)%FAMILY_LENGTH; 
			if(i!=j) table[j]= sap;
			else throw ChainLengthException{};
		}
	}
	
	void del(unsigned long sap){
		long pos= search(sap);
		if(pos!=-1){
			table[pos]= 0;
			printf("SAP: %lu deleted.\n", sap);	
		}else{
			printf("SAP:%lu not found!\n", sap);
		}
	}

};

int main(){

	HashTable db;

	short ans{};
	unsigned long sap{};
	while(1){
		printf("\nChoose one of the following options.\n");
		printf("1. Insert new SAP\n2. Delete SAP\n3. Search SAP\n4. Exit.\n");
		printf("Enter>>");
		cin>>ans;
		switch(ans){
			case 1:{
				printf("Enter new SAP:");
				cin>>sap;
				try{
					db.insert(sap);
				}catch(const ChainLengthException& e){
					printf("Exception Occured! %s\n", e.what());
				}
			} break;
			case 2:{
				printf("Enter SAP to be deleted:");
				cin>>sap;
				db.del(sap);
			} break;
			case 3:{
				printf("Enter SAP to be searched:");
				cin>>sap;
				long pos= db.search(sap);
				if(pos==-1) printf("SAP %lu not found!\n", sap);
				else printf("SAP %lu found at %lu.\n", sap, pos);
			} break;
			case 4:{
				return 0;
			} break;
			default:{
				printf("Incorrect Choice!\n");
			}
		}
	}

}
