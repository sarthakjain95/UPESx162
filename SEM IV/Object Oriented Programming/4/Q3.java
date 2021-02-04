
class Q3{

	public static void main(String args[]){

		float rate = (float)6.8;
		DailyWorker dw = new DailyWorker("Rajesh", rate);
		SalariedWorker sw = new SalariedWorker("Ravi", rate);

		dw.compay(32);
		sw.compay();
		System.out.println();

	}

}

class Worker{

	String name;
	float salaryRate;

	Worker(String name_, float rate){
		name = name_;
		salaryRate = rate;
	}

	void show(){
		System.out.println("\nName: " + name);
		System.out.println("Salary Rate: " + salaryRate);
	}

}

class DailyWorker extends Worker{

	DailyWorker(String name_, float rate){
		super(name_, rate);
	}

	void compay(int hours){
		super.show();
		float pay = super.salaryRate * hours;
		System.out.println("Hours worked: " + hours);
		System.out.println("Daily Worker Pay is " + pay);
	}

}

class SalariedWorker extends Worker{

	SalariedWorker(String name_, float rate){
		super(name_, rate);
	}

	void compay(){
		show();
		float pay = salaryRate * 40;
		System.out.println("Hours worked: " + 40);
		System.out.println("Salaried Worker Pay is " + pay);
	}

}
