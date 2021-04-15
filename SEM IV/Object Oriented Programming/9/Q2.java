
public class Q2{
    public static void main(String arg[]){
        PrintNumber even_printer = new PrintNumber("Even Number Printer", 2);
        even_printer.start();
        PrintNumber odd_printer = new PrintNumber("Odd Number Printer", 1);
        odd_printer.start();
    }
}

class PrintNumber extends Thread{
    int number;
    String name;
    PrintNumber(String name, int n){
        number = n;
        this.name = name;
    }
    public void run(){
        for(int i=0; i<10; i++){
            System.out.println(name + number);
            this.number += 2;
        }
    }
}
