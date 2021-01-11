import java.util.Scanner;

public class LagrangeInterpolation {
    static int x[], y[];
    
    public static void lagrange(double xa){
        int n = x.length;
        double sum = 0, temp;
        
        for(int i=0; i<n; i++){
            temp = 1;
            for(int j=0; j<n; j++){
                if(i!=j)
                    temp = temp*(xa-x[j])/(x[i]-x[j]);
            }
            sum += temp*y[i];
        }
        
        System.out.println("Interpolated value at "+xa+" is: "+sum);
    }
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        x = new int[n];
        y = new int[n];
        for(int i=0; i<n; i++)
        {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }
        lagrange(2);
    }
}
