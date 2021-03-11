
public class Q1{

	public static void main(String args[]){

		Student students[] = {
			new Student("Sarthak", 32), 
			new Student("Ravi", 35)
		};

		try{
			for(int i=0; i<3; i++){
				System.out.println("Accessing record " + (i+1));
				System.out.println(students[i].name + " " + students[i].rollno);
			}
		}catch(ArrayIndexOutOfBoundsException e){
			System.out.println("Exception caught: " + e.getMessage());
		}

	}

}

class Student{
	public String name;
	public int rollno;	
	Student(String _name, int rn){
		name = _name;
		rollno = rn;
	}
}
