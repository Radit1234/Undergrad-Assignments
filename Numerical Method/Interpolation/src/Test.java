import java.util.Scanner;

public class Test {
    static int n;
    static double x[], y[], diff[][], a[];
    
    public static void newton(double xp){
        diff = new double[n][n];
        a = new double[n];
        double sum, temp;
        for(int i=0; i<n; i++)
            diff[i][0] = y[i];
        
        for(int i=1; i<n; i++){
            for(int j=0; j<n-i; j++){
                diff[j][i] = (diff[j+1][i-1] - diff[j][i-1])/(x[i+j] - x[j]);
            }
        }
        
        for(int i=0; i<n; i++)
            a[i] = diff[0][i];
        
        sum = a[0];
        for(int i=1; i<n; i++){
            temp = 1;
            for(int j=0; j<i ; j++){
                temp *= (xp-x[j]);
            }
            sum += temp*a[i];
        }
        System.out.println("Value: "+sum);
    }
    
    public static void main(String args[]){
        
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        x = new double[n];
        y = new double[n];
        for(int i=0; i<n; i++){
            x[i] = sc.nextDouble();
            y[i] = sc.nextDouble();
        }
        
        newton(6);
    }
    
    
}
