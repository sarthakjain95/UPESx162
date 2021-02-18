
// WAP to implement Binary Search.

import java.util.Scanner;

public class Q5{

	static void BinarySearch(long arr[], long x){

		int start = 0, end = arr.length;
		int mid;

		while(start <= end){
			mid = start + (end - start) / 2;
			if(arr[mid] == x){
				System.out.println(x + " found at " + mid);
				return;
			}else{
				if(arr[mid] > x) end = mid-1;
				else start = mid+1;
			}
		}

		System.out.println(x + " not found!");

	}

	public static void main(String[] args){

		Scanner scanner = new Scanner(System.in);

		System.out.print("\nEnter size of array: ");

		int size = scanner.nextInt();
		long[] arr = new long[size];

		System.out.print("\nEnter elements of sorted array: ");
		for(int i=0; i<size; i++)
			arr[i] = scanner.nextLong();

		System.out.println("\nEnter element to search: ");
		long x = scanner.nextLong();

		BinarySearch(arr, x);

	}

}
