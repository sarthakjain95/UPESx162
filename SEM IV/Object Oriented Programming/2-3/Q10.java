
// Write a program to find the sum of all integers greater than 40 and less than 
// 250 that are divisible by 5.

class Q10{

	public static void main(String[] args){

		int lower_limit = 40;
		int upper_limit = 250;
		int factor = 5;

		long sum = 0;

		for(int i=lower_limit+1; i<upper_limit; i++){
			if(i % factor == 0){
				sum += i;
			}
		}

		System.out.print("Sum of all Numbers between " + lower_limit + " and " + upper_limit);
		System.out.print(" that are divisible by " + factor + " is ");
		System.out.println(sum);

	}

}
