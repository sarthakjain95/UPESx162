
// WAP for factorial computation.

import java.util.Scanner;

public class Q1{

	static long factorial(long n){
		if(n == 0 || n == 1){
			return 1;
		}else{
			return n * factorial(n-1);
		}
	}

	public static void main(String[] args){

		System.out.print("Enter a number: ");
		Scanner scanner = new Scanner(System.in);

		long n = scanner.nextLong();
		long facto = factorial(n);
		System.out.println("Factorial of " + n + " is " + facto);

	}

}

