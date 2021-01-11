import java.util.Scanner;

public class SecentMethod {
    static double coeff[];
    
    static double function(double x){
        int n = coeff.length - 1;
        double value=0, temp;        
        temp = coeff[n];
        
        for(int i=n-1; i>=0; i--){
           value = temp * x + coeff[i];
           temp = value;
        }
        return value;
    }
    
    static double secant(double x1,double x2){
        double E= 0.001,f1,f2,x3,root=0;
        while(true){
            f1=function(x1);
            f2=function(x2);
            x3=(f2*x1-f1*x2)/(f2-f1);
            if(Math.abs((x3-x2)/x3)> E){
                x1=x2;
                f1=f2;
                x2=x3;
                f2= function(x3);
            }
            else{
                root= x3;
                break;
            }
        }
        return root;
    }
    
    public static void main(String args[]){
        int n;
        double x1=4,x2=2;
        Scanner sc = new Scanner(System.in);
        
        System.out.println("enter the degree of the equation: ");
        n = sc.nextInt();
        coeff = new double[n+1];
        System.out.println("enter "+ (n+1) +" coefficients: ");
        for(int i=n; i>=0; i--)
            coeff[i]=sc.nextInt();
        
        
        System.out.println(secant(4,2));
    }
}
