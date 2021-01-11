import java.util.*;
import java.util.concurrent.Semaphore;

public class ProducerConsumer {
    
    static Scanner sc = new Scanner(System.in);
    static LinkedList<Integer> l = new LinkedList<>();
    static int capacity;
    static Semaphore empty;
    static Semaphore full = new Semaphore(0);
    static Semaphore mutex = new Semaphore(1);
    
    
    static class Producer implements Runnable {
        @Override
        public void run() {
            try {
                int item;
                do{

                    empty.acquire();
                    mutex.acquire();
                    System.out.println("Enter a number: ");
                    item = sc.nextInt();
                    //mutex.acquire();
                    
                    l.add(item);
                    System.out.println("Producer added "+item+" in the list.");
                    System.out.print("Numbers in list : ");
                    for(int ls : l )
                        System.out.print(ls+" ");
                    System.out.println();
                    Thread.sleep(2000);
                    mutex.release();
                    full.release();
                    //prod.release();
                    
                }while(true);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
    
    static class Consumer implements Runnable {
        @Override
        public void run() {
            try {
                int item;
                do{
            
                    full.acquire();       //down full
                    mutex.acquire();      //mutex down 
                    item = l.removeFirst();
                    System.out.println("Consumer consumed "+item+" from the list.");
                    System.out.print("Numbers in list : ");
                    for(int ls : l )
                        System.out.print(ls+" ");
                    System.out.println();
                    Thread.sleep(2000);
                    mutex.release();
                    empty.release();
                    //cons.release();
                }while(true);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
    
    
    public static void main(String args[])
    {
        System.out.print("Enter number of Items : ");
        capacity = sc.nextInt();
        empty = new Semaphore(capacity);
        Producer produce = new Producer();
        Consumer consumer = new Consumer();
        Thread t1 = new Thread(produce);
        t1.setName("Producer 1");
        Thread t2 = new Thread(consumer);
        t1.start();
        t2.start();
    }
}
