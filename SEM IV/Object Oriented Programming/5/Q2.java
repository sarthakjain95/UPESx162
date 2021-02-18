
// WAP for displaying Fibonacci series by taking range from the user.

import java.util.Scanner;

public class Q2{

	public static void main(String[] args){

		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Enter range: ");
		long range = scanner.nextLong();

		System.out.println("\nDisplaying " + range + " Fibonacci numbers:");

		long a = 0, b = 1, temp;
		System.out.print(a + " " + b + " ");
		for(long i=0; i<range; i++){
			temp = b;
			b = a + b;
			a = temp;
			System.out.print(b + " ");
		}

		System.out.println();
	}

}
