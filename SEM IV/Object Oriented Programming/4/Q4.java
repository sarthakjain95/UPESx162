
class Q4{

	public static void print_price(Lightning call){
		float charge = call.duration * 50;
		System.out.println("Lightning call charge: $" + charge);
	}

	public static void print_price(Regular call){
		float charge = call.duration * 20;
		System.out.println("Regular call charge: $" + charge);
	}

	public static void print_price(Urgent call){
		float charge = call.duration * 38;
		System.out.println("Urgent call charge: $" + charge);
	}	

	public static void main(String args[]){

		Lightning call1 = new Lightning(3);
		Regular call2 = new Regular(10);
		Urgent call3 = new Urgent(7);

		print_price(call1);
		print_price(call2);
		print_price(call3);

	}

}

class Call{
	float duration;
	Call(float dur){
		duration = dur;
	}
}

class Urgent extends Call{
	Urgent(float duration){
		super(duration);
	}
}

class Regular extends Call{
	Regular(float duration){
		super(duration);
	}
}

class Lightning extends Call{
	Lightning(float duration){
		super(duration);
	}
}

