import java.util.Scanner;

public class NewtonsMethod {
    static double coeff[];
    static double derivative[];
    
    
    public static double function(double coeff[] ,double x){
        int n = coeff.length - 1;
        double value=0, temp;        
        temp = coeff[n];
        
        for(int i=n-1; i>=0; i--){
           value = temp * x + coeff[i];
           temp = value;
        }
        return value;
    }
     
    public static double derivative( double x ){
         derivative = new double[coeff.length - 1];
         int n = derivative.length - 1;
         for(int i=n; i>=0; i--){
             derivative[i] = (i+1)* coeff[i+1];
             //System.out.println(coeff[i+1]+" : " +derivative[i]);
         }
         
         return function(derivative, x);
     }
    
    public static void syntheticDiv(double root){
        double temp=0;
        int n = coeff.length - 1;
        double quotient[] = new double[n];
        for(int i=n-1; i>=0; i--){
            quotient[i] = coeff[i+1] + root * temp;
            temp = quotient[i];
        }
        coeff = quotient;
        
    }
     
     public static void newtonsMethod(double x0)
     {
         double e=0.001, root=0, x1, f0, f0_derivative;
         int n = coeff.length - 1;
         while(n>1){
             while(true){
             
             f0 = function(coeff,x0);
             f0_derivative = derivative(x0);
             x1= x0 -(f0/ f0_derivative);
             //System.out.println(x0+" "+x1+" "+root);
             if(Math.abs(((x1-x0)/x1)) < e){
                 root = x1;
                 System.out.println("root :  " +root);
                 
                 break;
             }
             else
                 x0=x1;
         }
         syntheticDiv(root);
         x0 = root;
         n--;
     }
         root = -1 * coeff[0] / coeff[1];
         System.out.println("root : "+root);
         
     }
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the degree of the polynomial: ");
        int n = sc.nextInt();
        coeff = new double[n+1];
        
        System.out.println("Enter "+(n+1)+" coefficients: ");
        for(int i=n; i>=0 ; i--)
            coeff[i] = sc.nextDouble();
        
        newtonsMethod(1);
        
        //System.out.println(function(2));
        //derivative();
    }
    
    
}
