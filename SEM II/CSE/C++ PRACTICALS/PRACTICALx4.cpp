
// Practical 4
// Title: Friends to a Class and Inheritance
// Objective: To understand the concepts of Inheritance and Diamond Problem

// Final Result Calculation

#include<iostream>
#include<cstdio>
#include<string>

class Student{

	protected:

		std::string name;
		int roll_no;
		char gender;

	public:

		void get_student_details(){
			printf("\nEnter Student Name: ");
			std::getline(std::cin, name);
			printf("Enter Student Roll No. :");
			std::cin>>roll_no;
			printf("Enter Student Gender: ");
			std::cin>>gender;
		}

		void display_student_details(){
			printf("\nStudent Name: ");
			std::cout<<name;
			printf("\nStudent Roll No: %d", roll_no);
			printf("\nStudent Gender: %c", gender);
		}

};

class Internal_Exam: virtual public Student {

		float marks[6];
		float total;

	public:

		void calculate_internals_total(){
			total= 0;
			for(int n=0; n<6; n++) total+= marks[n];
		}

		float get_internals_marks(){
			calculate_internals_total();
			return total;
		}

		void input_internals_marks(){
			printf("\nEnter Marks for Internals:\n");
			for(int i=0; i<6; i++){
				printf("Enter Marks for Subject %d: ", i+1);
				std::cin>>marks[i];
			}
		}

		void display_internals_marks(){
			printf("\nDisplaying Marks For Internal Exams:");
			for(int i=0; i<6; i++)
				printf("\nMarks for Subject %d : %f", i+1, marks[i]);
		}
};

class External_Exam: virtual public Student {

                float marks[6];
                float total;

	public:

                void calculate_externals_total(){
                        total= 0;
                        for(int n=0; n<6; n++) total+= marks[n];
                }

                float get_externals_marks(){
                        calculate_externals_total();
                        return total;
                }

                void input_externals_marks(){
                        printf("\nEnter Marks for External:\n");
                        for(int i=0; i<6; i++){
                                printf("Enter Marks for Subject %d: ", i+1);
                                std::cin>>marks[i];
                        }
                }

                void display_externals_marks(){
                        printf("\nDisplaying Marks For External Exams:");
                        for(int i=0; i<6; i++)
                                printf("\nMarks for Subject %d : %f", i+1, marks[i]);
                }

};

class Result: public Internal_Exam, public External_Exam {

	float internals_marks_total, externals_marks_total;
	float final_result;

	public:

		void evaluate_final_result(){
			internals_marks_total= get_internals_marks();
			externals_marks_total= get_externals_marks();
			printf("\nInternals Total Marks: %.2f / 600.00", internals_marks_total);
			printf("\nExternals Total Marks: %.2f / 600.00", externals_marks_total);
			final_result= 0.4*internals_marks_total + 0.6*externals_marks_total;
			final_result/=6;
			printf("\n\nFinal Result is: %.2f%%",final_result);
		}

};


int main(){

	Result r1;

	r1.get_student_details();

	r1.input_internals_marks();
	r1.input_externals_marks();

	r1.display_student_details();
	r1.evaluate_final_result();

	std::cout<<std::endl;
	return 0;
}
