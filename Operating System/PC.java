
import java.util.Scanner;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;
 
class Q
{
    // an item
    int item;
    static int count = 0;
    int head=0, tail=0;
    int [] store  = new int[100];
    // semCon initialized with 0 permits
    // to ensure put() executes first
    
     static Scanner reader = new Scanner(System.in);
     static Semaphore emptyCount = new Semaphore(3);
     static Semaphore fullcount = new Semaphore(0);
     
     
     static Semaphore mutex = new Semaphore(1);
    
    static Semaphore semCon = new Semaphore(0);
     
    static Semaphore semProd = new Semaphore(1);
     
    // to get an item from buffer
    void get(int CID) throws InterruptedException
    {
      System.out.println("Consumer C" + CID + " is trying to down the fullcount ");
      fullcount.acquire();
      mutex.acquire();
      item = store[head];
      head++;
      System.out.println("Consumer C" + CID + " is trying to increase the the Emptycount ");
      //emptyCount.release();
      mutex.release();
      System.out.println("Consumer  C" + CID + " Consumed item : " + item);

    }
     
    // to put an item in buffer
    void put(int item, int PID) throws InterruptedException
    {
      
      System.out.println("Producer P"+ PID + " is trying to down the emptycount ");
      store[tail] = item;
      tail++;
      System.out.println("Producer P"+ PID + " is trying to increase the the Fullcount ");      
      System.out.println("Producer P"+ PID + " put item : " + item);


    }
}
 
// Producer class
class Producer implements Runnable
{
    Q q;
    int PID;
    Producer(Q q, int PID) {
        this.q = q;
        this.PID = PID;
        new Thread(this, "Producer P" + PID).start();
          }
     
    public void run() {  // Reading from System.in
         try {
             {
           
           q.emptyCount.acquire();
           q.mutex.acquire();
            //once finished
            System.out.println("Producer"  + PID + ": Enter a number:  ");
            int n = q.reader.nextInt(); // Scans the next token of the input as an int.
            q.put(n, PID); 
            q.mutex.release();
            q.fullcount.release();
            }
            
        } catch (InterruptedException ex) {
            Logger.getLogger(Producer.class.getName()).log(Level.SEVERE, null, ex);
        }
      
          
              
    }
}
 
// Consumer class
class Consumer implements Runnable
{
    int CID;
    Q q;
    int item;
    Consumer(Q q, int CID){
        this.q = q;
        this.item = 0;
        this.CID = CID;
        new Thread(this, "Consumer C " + CID).start();
    }
     
    public void run()
    {
        try {
        {
           
           q.get(CID);
           //item++;
           q.count++;
           
        }
        
        } catch (InterruptedException ex) {
            Logger.getLogger(Consumer.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
 
// Driver class
class PC
{
    public static void main(String args[]) 
    {
        // creating buffer queue
        Q q = new Q();
         
        // starting consumer thread
        new Consumer(q,0);
        new Consumer(q,1);              //3 p 2 c
        
        
        new Producer(q,0);
        new Producer(q,1);
        new Producer(q,2);
       // new Producer(q,2);
        //new Consumer(q);
         
        // starting producer thread
    }
}