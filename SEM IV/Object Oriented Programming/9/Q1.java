
class Q1{
    public static void main(String args[]){
        ThreadExtension te = new ThreadExtension(10);
        te.start();
        RunnableImplementation ri = new RunnableImplementation(1);
        ri.start();
    }
}

class RunnableImplementation implements Runnable{
    private Thread t;
    private int n;
    RunnableImplementation(int num){
        n = num;
        System.out.println("Created RunnableImplementation class object.");
    }
    public void run(){
        System.out.println("Running RunnableImplementation.run in a new thread.");
        for(int i=0; i<5; i++){
            System.out.println("RunnableImplementation class prints " + n);
            n += 10;
        }
        System.out.println("RunnableImplementation class exiting.");
    }
    public void start () {
        if (t == null) {
            t = new Thread(this);
            t.start();
        }
    }
}

class ThreadExtension extends Thread{
    private int n;
    ThreadExtension(int num){
        n = num;
        System.out.println("Created ThreadExtension class object.");
    }
    public void run(){
        System.out.println("Running ThreadExtension.run in a new thread.");
        for(int i=0; i<5; i++){
            System.out.println("ThreadExtension class prints " + n);
            n += 10;
        }
        System.out.println("ThreadExtension class exiting.");
    }
}

// Bad choice of log messages eh?
