
// Write a program to accept three digits (i.e. 0 - 9) and print all its possible 
// combinations. (For example, if the three digits are 1, 2, 3 than all possible
// combinations are: 123, 132, 213, 231, 312, 321.)

import java.util.Scanner;

class AllCombinations{

	static void printCombinations(String[] options, String previous_part){

		if(options.length == 1){
			System.out.println(previous_part + options[0]);
		} else {
			String[] sub_combinations = new String[options.length-1];
			for(int i=0; i<options.length; i++){
				for(int j=0, idx=0; j<options.length; j++){
					if(j != i){
						sub_combinations[idx] = options[j];
						idx += 1;
					}
				}
				printCombinations(sub_combinations, previous_part + options[i]);
			}
		}

	}

	public static void main(String[] args){

		int n = 3;
		String[] digits = new String[n];
		Scanner input = new Scanner(System.in);

		for(int i=0; i<n; i++){
			System.out.print("Enter digit " + (i+1) + ":");
			digits[i] = input.nextLine();
		}

		System.out.print("All combinations are:\n");
		printCombinations(digits, "");

	}

}
