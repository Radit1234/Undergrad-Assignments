import java.util.Scanner;

public class NewtonsDivided {
    static double x[], y[],diff[][],a[];
    
    public static void newtonsDividedDiff(double xa){
        int n = x.length;
        double sum, temp;
        
        diff = new double[n][n];
        a = new double[n];
        
        
        for(int i=0; i<n; i++){
            diff[i][0] = y[i];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<n-i; j++){
                diff[j][i] = (diff[j+1][i-1] - diff[j][i-1])/ (x[i+j]-x[j]);
                //System.out.printf("%.3f\t",diff[j][i]);
            }
            //System.out.println();
        }
        
        for(int i=0; i<n; i++)
            a[i] = diff[0][i];
        
        sum = a[0];
        
        for(int i=1; i<n; i++){
            temp = 1;
            for(int j=0; j<i; j++){
                temp = temp * (xa-x[j]);
            }
            sum = sum + a[i] * temp;
        }
        
        System.out.println("Interpolated value: "+sum);
        
    }
    
    public static void main(String args[]){
        
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        x = new double[n];
        y = new double[n];
        for(int i=0; i<n; i++)
        {
            x[i] = sc.nextDouble();
            y[i] = sc.nextDouble();
        }
        newtonsDividedDiff(2.5);
    }
}
