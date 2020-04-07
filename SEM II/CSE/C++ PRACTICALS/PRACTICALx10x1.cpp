// EXPERIMENT – 10

// Title: Hash tables
// Objective: To understand the concepts of Hash tables

// 1. Implement a hash function on student SAP-ID and categorize them in to their 10 families based
// on the last three digits. (E.g. Student with SAP-ID 5000423 belongs to family 9 and student
// with SAP-ID 5000425 belongs to family 2 based on last three digits)

#include<iostream>
using namespace std;

unsigned long get_hash(unsigned long sapid){
	unsigned long sum{sapid%1000};
	while(sum>9) sum-=9;
	return sum;
}

int main(){

	printf("SAP ID: %lu\tFamily:%lu\n", 500075185, get_hash(500075185));
	printf("SAP ID: %lu\tFamily:%lu\n", 500075423, get_hash(500075423));
	printf("SAP ID: %lu\tFamily:%lu\n", 500075425, get_hash(500075425));

	return 0;
}