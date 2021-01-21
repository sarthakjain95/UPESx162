
// Write a program to input a number of a month (1 - 12) and print its equivalent 
// name of the month. (e.g., 1 to Jan, 2 to Feb. 12 to Dec.)

import java.util.Scanner;

class NumberedMonths{

	public static void main(String[] args){

		Scanner input = new Scanner(System.in);
		int month_index = -1;

		System.out.print("Enter month index: ");
		month_index = input.nextInt();

		System.out.print("Corresponding month is: ");

		switch(month_index){
			case 1: System.out.print("Jan\n"); break;
			case 2: System.out.print("Feb\n"); break;
			case 3: System.out.print("Mar\n"); break;
			case 4: System.out.print("Apr\n"); break;
			case 5: System.out.print("May\n"); break;
			case 6: System.out.print("Jun\n"); break;
			case 7: System.out.print("Jul\n"); break;
			case 8: System.out.print("Aug\n"); break;
			case 9: System.out.print("Sep\n"); break;
			case 10: System.out.print("Oct\n"); break;
			case 11: System.out.print("Nov\n"); break;
			case 12: System.out.print("Dec\n"); break;
			default: System.out.print("Invalid choice!\n");
		}

	}

}
