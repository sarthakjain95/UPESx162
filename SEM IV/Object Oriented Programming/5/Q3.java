
// WAP for GCD calculation.

import java.util.Scanner;

public class Q3 {

	static long gcd(long a, long b){
		if(b == 0) return a;
		return gcd(b, a%b);
	}

	public static void main(String[] args){

		Scanner scanner = new Scanner(System.in);

		System.out.print("Enter two numbers: ");
		long a = scanner.nextLong();
		long b = scanner.nextLong();
		long ans = gcd(a, b);

		System.out.println("\nGCD of " + a + " and " + b + " is " + ans);

	}

}
