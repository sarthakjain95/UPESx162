
// WAP to implement Bubble Sort, Insertion Sort, Merge Sort.

import java.util.Scanner;

public class Q4{

	static void PrintArray(long arr[]){
		for(int i=0; i<arr.length; i++){
			System.out.print(arr[i] + " ");
		}
		System.out.print("\n\n");
	}

	static void BubbleSort(long arr[]){
		long temp;
		for(int i=arr.length-1; i>0; i--){
			for(int j=0; j<i; j++){
				if(arr[j] > arr[j+1]){
					temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	
	static void InsertionSort(long arr[]){
		long temp; int j;
		for(int i=1; i<arr.length; i++){
			temp = arr[i]; j = i - 1;
			while(j>=0 && arr[j]>temp){
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = temp;
		}
	}

	static void Merge(long arr[], int start, int mid, int end){

		int i = 0, j = 0, k = start;

		long[] a = new long[mid - start + 1];
		long[] b = new long[end - mid];

		for(i=0; i<a.length; i++) a[i] = arr[i+start];
		for(j=0; j<b.length; j++) b[j] = arr[j+mid+1];
		i=0; j=0;

		while(i<a.length && j<b.length){
			if(a[i] < b[j]){
				arr[k] = a[i];
				i++;
			}else{
				arr[k] = b[j];
				j++;
			}
			k++;
		}

		while(i < a.length){
			arr[k] = a[i];
			i++; k++;
		}

		while(j < b.length){
			arr[k] = b[j];
			j++; k++;
		}	

	}

	static void MergeSort(long arr[], int start, int end){
		if(start < end){
			int mid = start + (end - start) / 2;
			MergeSort(arr, start, mid);
			MergeSort(arr, mid+1, end);
			Merge(arr, start, mid, end);
		}
	}

	public static void main(String[] args){

		Scanner scanner = new Scanner(System.in);

		System.out.print("\nEnter size of array: ");

		int size = scanner.nextInt();
		long[] arr = new long[size];

		System.out.print("\nEnter elements of array: ");
		for(int i=0; i<size; i++)
			arr[i] = scanner.nextLong();

		System.out.print("\nSelect Sorting Algorithm to use:\n");
		System.out.println("1. Bubble Sort");
		System.out.println("2. Insertion Sort");
		System.out.println("3. Merge Sort");

		System.out.print("Enter choice: ");
		long choice = scanner.nextLong();

		if(choice == 1) BubbleSort(arr);
		else if(choice == 2) InsertionSort(arr);
		else if(choice == 3) MergeSort(arr, 0, arr.length-1);
		else System.out.println("Invalid choice!");

		System.out.println("\nSorted array is: ");
		PrintArray(arr);
	}

}
