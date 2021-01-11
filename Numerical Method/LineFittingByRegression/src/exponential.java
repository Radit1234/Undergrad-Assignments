import java.util.Scanner;

public class exponential {
    
    static double x[], y[];  
    
    public static void exponentialReg(int n){
        double sumy = 0, sumfx = 0, sumyfx = 0, sumfxfx = 0, a , b , e =0.001, fx, fxmean, ymean, denom ;
        
        for(int i=0; i<n; i++){
            fx = Math.exp(x[i]);
            //System.out.println("fx: "+fx);
            sumfx = sumfx + fx;
            sumy = sumy + y[i];
            sumfxfx = sumfxfx + fx * fx;
            sumyfx = sumyfx + y[i] * fx;
        }
        fxmean = sumfx/n;
        ymean = sumy/n;
        denom = n*sumfxfx - sumfx *sumfx;
        if(Math.abs(denom) > e){
            b = (n*sumyfx - sumfx * sumy) / denom;
            a = ymean - b*fxmean;
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
        exponentialReg(n);
    }
}
