
public class Q4{
	public static void eval(int v1, int v2){
		System.out.println("Evaluating for directions: " + v1 + " " + v2);
		try{
			if(v1 != v2){
				throw new ChanceOfCollision();
			}else{
				System.out.println("Vehicles will not collide!");
			}
		}catch(ChanceOfCollision err){
			System.out.println("Exception caught: " + err.getMessage());
		}
	}
	public static void main(String args[]){
		int v1_direction = 1;
		int v2_direction = -1;
		eval(1, -1);
		eval(-1, 1);
		eval(1, 1);
		eval(-1, -1);
	}
}

class ChanceOfCollision extends Exception{
	ChanceOfCollision(){
		super("There is a chance of collision!");
	}
}
