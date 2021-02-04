
class Q5{

	public static void main(String args[]){

		Manager manager = new Manager("Ravi Kumar", 435567, 125006, "Advertising");

		manager.print_details();
		manager.increase_salary();
		manager.print_details();

	}

}

class Employee{

	String name;
	long empid;
	double salary;

	Employee(String name_, long empid_, double salary_){
		name = name_;
		empid = empid_;
		salary = salary_;
	}

	String get_name(){
		return name;
	}

	double get_salary(){
		return salary;
	}

	void increase_salary(){
		double percentage_increase = 200;
		salary = salary + (salary * (percentage_increase / 100));
		System.out.println("\n[Increased Salary for Employee Id:" + empid + "]\n");
	}

}

class Manager extends Employee{

	String department;

	Manager(String name, long empid, double salary, String department){
		super(name, empid, salary);
		this.department = department;
	}

	void print_details(){
		System.out.println("ID: " + empid);
		System.out.println("Name: " + name);
		System.out.println("Department: " + department);
		System.out.println("Salary: " + salary);
	}

}
