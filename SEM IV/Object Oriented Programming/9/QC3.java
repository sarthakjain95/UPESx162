
import java.io.*;
import java.util.*;

class QC3{
    public static void main(String[] args){
        // Make hashset
        HashSet<String> more_numbers = new HashSet<String>();
        more_numbers.add("Five");
        more_numbers.add("Six");
        System.out.println("First HashSet: " + more_numbers);
        // Make another hashset
        HashSet<String> numbers = new HashSet<String>();
        numbers.add("One");
        numbers.add("Two");
        numbers.add("Three");
        numbers.add("Four");
        System.out.println("Second HashSet: " + numbers);
        // Add one hashset to another
        numbers.addAll(more_numbers);
        System.out.println("Combined HashSet: " + numbers);
        // Delete all values at once 
        numbers.clear();
        System.out.println("Combined HashSet after clear was called: " + numbers);
        // Search user defined object
        HashSet<TypicalClass> arr = new HashSet<TypicalClass>();
        TypicalClass tc = new TypicalClass(1, 2, 'c');
        arr.add(tc);
        arr.add(new TypicalClass(212, 234, 'y'));
        arr.add(new TypicalClass(789, 267, 'i'));
        System.out.println("HashSet for user defined objects: " + arr);
        //
        TypicalClass tc2 = new TypicalClass(1, 2, 'b');
        if(arr.contains(tc)) System.out.println("HashSet contains " + tc);
        else System.out.println("HashSet does not contain " + tc);
        if(arr.contains(tc2)) System.out.println("HashSet contains " + tc2);
        else System.out.println("HashSet does not contain " + tc2);
    }
}

class TypicalClass{
    int i, j;
    char k; 
    TypicalClass(int a,  int b, char c){
        i = a; 
        j = b;
        k = c;
    }
    public String toString(){
        return "(" + i + ", " + j + ", " + k + ")";
    }
}
