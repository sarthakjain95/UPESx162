
// Write a program to implement a command line calculator.

import java.util.Scanner;


class CommandLineCalculator{

	static double resolve(double a, double b, char op){

		switch(op){
			case '+': return a + b;
			case '-': return a - b;
			case '*': return a * b;
			case '/': return a / b;
		}

		System.out.println("\nInvalid Operation " + op);
		return -1;

	}

	public static void main(String[] args){

		Scanner input = new Scanner(System.in);
		double a, b;
		char sym;

		System.out.print("Enter First Number:");
		a = input.nextDouble();

		System.out.print("Enter Second Number: ");
		b = input.nextDouble();

		System.out.print("Enter Operation Symbol: ");
		sym = input.next().charAt(0);

		double result = resolve(a, b, sym);
		System.out.println("\n" + a + sym + b + " is " + result);

	}

}
