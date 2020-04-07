
// EXPERIMENT – 8

// Title: File Handling
// Objective: To understand the concept of File Handling

// 2. Define class ‘Residence’ with data member house_no, income, house_name, and house_type.
// The class has the following member functions:
// a. void input() – obtains house_no, house_name and income. Calls assign()
// b. void assign() – allocates house type based on income (A/B/C/etc.)
// c. void output() – prints house details
// d. int house() – returns house_no
// main() is menu driven to (1) add multiple records as required into a binary file in append mode
// (2) Enter house_no to locate the record in the binary file and modify it using random access (3)
// display records from the binary file.

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Residence{

	size_t house_no, income;
	char house_name[101], house_type;

	public:

		void input(){
			printf("Enter House No. :");
			cin>>house_no;
			printf("Enter House Name:");
			string name;
			// cin.getline(house_name, 100);
			cin>>name;
			strcpy(house_name, name.c_str());
			printf("Enter Income:");
			cin>>income;
			assign();
		}

		void assign(){
			if(income<5000) house_type= 'C';
			else if(income<50000) house_type= 'B';
			else house_type= 'A';
		}

		void output(){
			printf("House Number is:%llu\n", house_no);
			printf("House Name is %s\n", house_name);
			printf("Income of House is:%llu\n", income);
			printf("House type is: %c\n", house_type);
		}

		size_t house(){ return house_no; }

};

int main(){

	size_t n{};
	printf("Enter Number of records to Enter:");
	cin>>n;
	
	Residence temp_res;
	ofstream f_out("records.bin", ios::app | ios::binary);
	for(size_t i{}; i<n; i++){
		temp_res.input();
		f_out.write((char*)&temp_res, sizeof(temp_res));
	}	
	f_out.close();

	size_t hno{};
	printf("Enter House no. to Search:");
	cin>>hno;

	fstream f("records.bin", ios::in | ios::out | ios::binary);
	f.seekg(0, ios::beg);
	int64_t pos{};
	while(!f.eof()){

		f.read((char*)&temp_res, sizeof(temp_res));
		
		if( temp_res.house() == hno ){

			f.seekp(pos*sizeof(temp_res), ios::beg);

			printf("Enter new details for the Residence:\n");
			Residence temp_res;
			temp_res.input();

			f.write((char*)&temp_res, sizeof(temp_res));

			f.close();
			return 0;
		}

		pos++;

	}
	f.close();
	printf("Record not found!\n");

	return 0;
}
