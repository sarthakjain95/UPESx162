
// Write a program to find the largest of 3 numbers.

class LargestOf3Numbers{

	static int max(int a, int b){
		if( a > b ){
			return a;
		} else {
			return b;
		}
	}
	
	public static void main(String[] args){
		int a = 3, b = 4, c = 5;
		int largest = max(max(a, b), c);
		System.out.println("Largest Number is " + largest);
	}
	
}
