
import java.util.Scanner;

public class Q2{

	public static void main(String args[]){

		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter two numbers: ");
		
		int a = scanner.nextInt();
		int b = scanner.nextInt();

		try{
			int result = a/b;
			System.out.println("Division Result is: " + result);
		}catch(ArithmeticException e){
			System.out.println("\nCaught Exception: " + e.getMessage());
		}

	}

}
