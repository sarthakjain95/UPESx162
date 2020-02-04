
// Practical 4
// Title: Friends to a Class and Inheritance
// Objective: To understand the concepts of friend function, friend class and Inheritance

// Create a student class with student sapid, name, marks of 6 subjects as its members and
// initializes the details. Use friend class that access the details of student, calculates total marks,
// average marks and prints the result.

#include<iostream>
#include<cstdio>
#include<string>

class Student{

	unsigned long sapid;
	std::string name;
	float marks[6];

	public:

		void GetStudentDetails(){

			printf("\nEnter Name:");
			getline(std::cin, name);
			printf("Enter SAP ID:");
			std::cin>>sapid;
			
			for(int n=0; n<6; n++){
				printf("\nEnter Marks for Subject %d: ", n+1);
				std::cin>>marks[n];
			}

		}

		void DisplayStudentDetails(){

			printf("\nStudent SAP ID: %lu", sapid);
			printf("\nStudent Name: ");
			std::cout<<name;

		}


	friend class Result;
};

class Result{

	float totalMarks;

	public:

		void CalculateResult(Student &x){

			x.DisplayStudentDetails();

			totalMarks= 0;
			for(int n=0; n<6; n++) totalMarks+= x.marks[n];
			printf("\nTotal Marks: %.2f / 600.00", totalMarks);
			printf("\nPercentage Obtained: %.2f%%", totalMarks/6);

		}

};


int main(){

	Student stu;
	stu.GetStudentDetails();

	Result res;
	res.CalculateResult(stu);

	std::cout<<std::endl;
	return 0;
}
