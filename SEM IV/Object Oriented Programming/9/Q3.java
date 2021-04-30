

class Q3{
    public static void main(String[] args) throws InterruptedException {
        IncrementCounter[] arr = new IncrementCounter[10];
        for(int i=0; i<10; i++){
            IncrementCounter ic = new IncrementCounter();
            arr[i] = ic;
        }
        Thread.sleep(100);
        System.out.println("Final Counter Value: " + arr[9].i);
    }
}

class Counter{
    static int i = 0;
}

class IncrementCounter extends Counter implements Runnable{
    Counter c = this;
    Thread t;
    IncrementCounter(){
        t = new Thread(this);
        t.start();
    }
    public void run(){
        SynchronousIncrement.increment(c);
    }
}

class SynchronousIncrement{
    synchronized static void increment(Counter c){
        c.i++;
        System.out.println("Incremented! i is now " + c.i);
    }
}
