
public class Q3{
	public static void main(String args[]){
		if(args.length == 2){
			int a, b;
			try{
				try{
					a = Integer.parseInt(args[0]);
					b = Integer.parseInt(args[1]);
				}catch(Exception e){
					throw new NonNumeric();
				}
				System.out.println("Modulo result is: " + (a%b));
			}catch(NonNumeric err){
				System.out.println("Caught Exception: " + err.getMessage());
			}
		}else{
			System.out.println("Pass two command line arguments!");
		}
	}
}

public class NonNumeric extends Exception{
	public NonNumeric(){
		super("Cannot use modulo on non-numeric objects!");
	}
}
