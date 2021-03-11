
import java.util.Scanner;

public class Q5{
	public static void main(String args[]){

		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter details:");

		String name = "";
		int age = 0, age_limit = 50;

		name = scanner.next();

		try{
			Integer.parseInt(name);
			throw new InvalidName();
		}catch(InvalidName err){
			System.out.println("Exception caught: " + err.getMessage());
			System.exit(-1);
		}catch(Exception e){ 
			System.out.println("[+] Given name is valid."); 
		}

		try{
			age = scanner.nextInt();
			if(age > age_limit) throw new AboveAgeLimit(age);
		}catch(AboveAgeLimit err){
			System.out.println("Exception caught: " + err.getMessage());
			System.exit(-1);
		}
		
		Employee e = new Employee(name, age);
		System.out.println("Employee details: ");
		System.out.println("Name: " + e.name);
		System.out.println("Age: " + e.age);

	}
}

class Employee{
	public String name;
	public int age;
	Employee(String n, int a){ name = n; age = a; }
}

class InvalidName extends Exception{
	InvalidName(){ super("Invalid name!\n * Names cannot contain numbers"); }
}

class AboveAgeLimit extends Exception{
	AboveAgeLimit(int n){ super("Give age '" + n + "' is over the age limit!"); }
}
