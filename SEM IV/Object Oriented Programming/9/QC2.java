
import java.io.*;
import java.util.*;

class QC2{
    public static void main(String[] args){
        // Make hashmap
        HashMap<Integer, String> value_to_number = new HashMap<Integer, String>();
        value_to_number.put(1, "One");
        value_to_number.put(2, "Two");
        value_to_number.put(3, "Three");
        value_to_number.put(4, "Four");
        // Check 2 keys
        if(value_to_number.containsKey(5)){
            System.out.println("Hashmap contains 5.");
        }else{
            System.out.println("Hashmap does not contain 5.");
        }
        if(value_to_number.containsKey(3)){
            System.out.println("Hashmap contains 3.");
        }else{
            System.out.println("Hashmap does not contain 3.");
        }  
        // Check value
        System.out.println("Hashmap value at " + 4 + " is " + value_to_number.get(4));
        System.out.println("Hashmap value at " + 1 + " is " + value_to_number.get(1));
        // Get all keys
        System.out.println(value_to_number);
    }
}
