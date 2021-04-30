
class Q4{
    public static void main(String[] args) throws InterruptedException {
        Process[] threads = new Process[5];
        for(int i=0; i<5; i++){
            Process p = new Process(i+1);
            threads[i] = p;
        }
        // Print Priorities
        System.out.println("Priorities:");
        for(int i=0; i<5; i++){
            System.out.print(threads[i].getPriority() + " ");
        }
        System.out.println();
        // Start threads
        for(int i=1; i<6; i++){
            threads[i%5].start();
        }
        // Put high priority thread to sleep
        threads[1].sleep(100);
        threads[2].sleep(100);
        // Check which thread lasts the longest
        boolean[] is_alive_arr = new boolean[5];
        for(int i=0; i<5; i++) is_alive_arr[i] = true;
        int alive_counter = 5;
        int last_idx = -1;
        while(alive_counter > 0){
            for(int i=0; i<5; i++){
                if(is_alive_arr[i] == true && threads[i].isAlive() == false){
                    is_alive_arr[i] = false;
                    alive_counter--;
                    last_idx = i;
                }
            }
        }
        System.out.println();
        System.out.println("Thread " + (last_idx + 1) + " lasted the longest");
        System.out.println("It had priority level:" + threads[last_idx].getPriority());
    }
}

class Process extends Thread{
    Process(int priority){
        Thread.currentThread().setPriority(priority);
    }
    public void run(){
        System.out.println("Process with priority " + Thread.currentThread().getPriority() + " started work.");
        try{
            Thread.sleep(500); // Simulating work!
        }catch(InterruptedException ex){
            System.out.println("Could not sleep!");
        }
        System.out.println("Process with priority " + Thread.currentThread().getPriority() + " finished work.");
    }
}
