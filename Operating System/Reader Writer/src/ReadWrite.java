import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.Semaphore;

/**
 *
 * @author MSI PC
 */
public class ReadWrite {

    /**
     * @param args the command line arguments
     */
    static Scanner reader = new Scanner(System.in);
    static int[] array = new int[100];
    static Semaphore readLock = new Semaphore(1);
    static Semaphore writeLock = new Semaphore(1);
    static int readCount = 0;
    static int n=0;
    static int head =0; 
    static int tail =0;
    
     static class Read implements Runnable {
        @Override
        public void run() {
            try {
                while(true){
                if(head>0){
                readLock.acquire();
                readCount++;
                if(readCount==1)
                    writeLock.acquire();
                readLock.release();
                readLock.acquire();
                Random rand = new Random();
                int random = (int) (Math.random() * head + 0);
                System.out.println(Thread.currentThread().getName() + " is READING"+" "+array[random]);
                Thread.sleep(1500);
                System.out.println(Thread.currentThread().getName() + " Leaves");
                readCount--;
                if(readCount==0)
                    writeLock.release();
                readLock.release();
                
                    }
                }
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
     
      static class Write implements Runnable {
        @Override
        public void run() {
            try {
                
                writeLock.acquire();
                
                System.out.println(Thread.currentThread().getName() + " is WRITING");
                System.out.println("Enter numbers : ");
                for(int i=0;i<n;i++){
                    int a=reader.nextInt();
                    array[head] = a;
                    head++;
                }
                System.out.println("Data in Buffer:");
                for(int i=0;i<head;i++){
                    System.out.println(array[i]+" ");
                    tail++;
                    
                }
                
                Thread.sleep(2500);
                System.out.println(Thread.currentThread().getName() + " has finished WRITING");
                writeLock.release();
               
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
    public static void main(String[] args) {
        // TODO code application logic here
        n=reader.nextInt();
        Read read = new Read();
        Write write = new Write();
        array[0] = 2; head++;
        array[1] = 3; head++;
        array[2] = 5; head++;
        Thread t1 = new Thread(read);
        t1.setName("Reader1");
        Thread t2 = new Thread(read);
        t2.setName("Reader2");
        Thread t3 = new Thread(write);
        t3.setName("Writer0");
        Thread t4 = new Thread(read);
        t4.setName("Reader3");
        Thread t5 = new Thread(write);
        t5.setName("Writer1");
        
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
    }
    
}
