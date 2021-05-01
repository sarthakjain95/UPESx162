
import java.io.*;
import java.util.*;

class QC1{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int size = 0;
        System.out.print("Enter number of strings to enter:");
        size = Integer.parseInt(input.nextLine());
        // 
        ArrayList<String> arr = new ArrayList<String>();
        for(int i=0; i<size; i++){
            String s = input.nextLine();
            arr.add(s);
        }
        // Reading through an iterator
        System.out.println("\nArray contains:");
        Iterator<String> it = arr.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }
        // Making a clone
        ArrayList arr_clone = new ArrayList<String>();
        arr_clone = (ArrayList)arr.clone();
        // Printing the contents of the clone
        System.out.println("\nArray Clone: " + arr_clone);
        // Reverse array
        Collections.reverse(arr);
        System.out.println("Reversed Array: " + arr);     
    }
}
