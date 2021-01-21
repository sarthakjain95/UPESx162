
// Write a program to add two number using command line arguments.

class AddCommandLineArguments{

	public static void main(String[] args){

		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);
		int sum = a + b;

		System.out.println("Sum of " + a + " and " + b + " is " + sum);

	}

}
