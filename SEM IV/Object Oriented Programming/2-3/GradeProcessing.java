
// Write a program to accept 10 student’s marks in an array, arrange it into ascending 
// order, convert into the following grades and print marks and grades
// in the tabular form.
// 		Between 40 and 50: PASS
// 		Between 51 and 75: MERIT
// 		and above: DISTINCTION

import java.util.Scanner;

class GradeProcessing{

	public static void sort(float[] arr){

		float temp;
		for(int i=arr.length; i>0; i--){
			for(int j=1; j<i; j++){
				if(arr[j] < arr[j-1]){
					temp = arr[j];
					arr[j] = arr[j-1];
					arr[j-1] = temp;
				}
			}
		}

	}

	public static String marksToGrade(float marks){
		if(marks < 40){
			return "FAIL";
		} else if (marks >=40 && marks <= 50) {
			return "PASS";
		} else if (marks >= 51 && marks <= 75) {
			return "MERIT";
		} else {
			return "DISTINCTION";
		}
	}

	public static void main(String[] args){

		int n_students = 10;
		float[] marks = new float[n_students];
		Scanner input = new Scanner(System.in);

		for(int i=0; i<n_students; i++){
			System.out.print("Enter marks for student " + (i+1) + ": ");
			marks[i] = input.nextFloat();
		}

		// Arrange is ascending order (Sorting)
		sort(marks);

		for(int i=0; i<n_students; i++){
			System.out.print("Student ID: " + i + "\tMarks: " + marks[i] + "\tGrade: ");
			System.out.println( marksToGrade(marks[i]) );
		}

	}

}
