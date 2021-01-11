import java.util.Scanner;

public class StraightLine {
    
    static double x[], y[];  
    
    public static void linearReg(int n){
        double sumx = 0, sumy = 0, sumxx = 0, sumxy = 0,  xmean, ymean, denom, e=0.0001, a, b;
        for(int i=0; i<n; i++){
            sumx = sumx + x[i];
            sumy = sumy + y[i];
            sumxx = sumxx + x[i] * x[i];
            sumxy = sumxy + x[i] * y[i];
        }
        xmean = sumx/n;
        ymean = sumy/n;
        denom = n*sumxx - sumx *sumx;
        if(Math.abs(denom) > e){
            b = (n*sumxy - sumx * sumy) / denom;
            a = ymean - b*xmean;
            System.out.println("The coefficients are: ");
            System.out.printf("a = %.3f\nb = %.3f",a,b);
        }
        else
            System.out.println("No solution exist");
    }
            
    public static void main(String args[]){
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        x = new double[n];
        y = new double[n];
        for(int i=0; i<n;i++){
            x[i] = sc.nextDouble();
            y[i] = sc.nextDouble();
        }
        
        linearReg(n);
    }
}
