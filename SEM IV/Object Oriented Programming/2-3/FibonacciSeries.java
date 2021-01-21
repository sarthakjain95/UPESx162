
// Write a program to print Fibonacci series using loop.

class FibonacciSeries{

	public static void main(String[] args){

		int limit = 20;
		long a = 0, b = 1;
		long temp;

		System.out.println("Fibonacci Series Upto " + limit + "terms:\n");
		System.out.print(a + " " + b);

		for(int i=0; i<limit; i++){
			temp = b;
			b = b + a;
			a = temp;
			System.out.print(" " + b);
		}

		System.out.println();

	}

}
