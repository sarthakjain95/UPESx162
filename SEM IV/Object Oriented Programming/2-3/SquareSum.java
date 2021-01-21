
// Write a Java Program to accept 10 numbers in an array and compute the square of 
// each number. Print the sum of these numbers.

import java.util.Scanner;

class SquareSum{

	public static void main(String[] args){

		Scanner input = new Scanner(System.in);

		int n = 10;
		long[] nums = new long[n];
		long[] squares = new long[n];
		long sum = 0;

		for(int i=0; i<n; i++){
			System.out.print("Enter " + i + " number: ");
			nums[i] = input.nextLong();
		}

		System.out.print("\nSquare of the given numbers are:\n");
		for(int i=0; i<n; i++){
			squares[i] = nums[i] * nums[i];
			sum += squares[i];
			System.out.print(squares[i] + " ");
		}

		System.out.print("\nSum of Square is " + sum + "\n");

	}

}
