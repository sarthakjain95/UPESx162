
// Produces an error

class Q1{

	public static void main(String args[]){

		Derived derived = new Derived(32, 45, 67);

		System.out.println("derived.i = " + derived.i);
		System.out.println("derived.j = " + derived.j);
		System.out.println("derived.k = " + derived.k);

	}

}

class Example{

	private int i;
	public int j;

	Example(int a, int b){
		i = a;
		j = b;
	}

}

class Derived extends Example{

	public int k;
	Derived(int a, int b, int c){
		super(a, b);
		k = c;
	}

}
