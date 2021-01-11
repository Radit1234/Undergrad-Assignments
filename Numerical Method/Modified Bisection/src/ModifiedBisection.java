import java.util.Scanner;

public class ModifiedBisection {
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
    
    public static void modifiedBisection(double a, double b){
        double interval= 0.5, x1, x2,x0, f0,f1,f2, root=0, e=0.001;
        
        while(true){
        x1=a;
        x2= x1 + interval;
        f1 = function(x1);
        f2 = function(x2);
        //System.out.println(x1+" "+x2+" "+f1+" "+f2+" ");
        
        if(f1*f2<=0)
        {
            while(true){
                x0 = (x1+x2)/2;
                f0 = function(x0);
                
                //System.out.println("loop2: "+x0+" "+f0);
                
                if(f1*f0 < 0){
                    x2 = x0;
                    f2 = f0;
                }
                else{
                    x1= x0;
                    f1= f0;
                  
                }
                if(Math.abs(((x2-x1)/x2)) < e){
                    root= (x1 + x2)/2;
                    System.out.println("root: "+root);
                    break;
                }
            
            }
            
        }
       
        if(x2<b){
               a= x2;
            }
        else
            break;
        
        }
    }
    
    public static void main(String args[]){
        int n;
        Scanner sc = new Scanner(System.in);
        
        System.out.println("enter the degree of the equation: ");
        n = sc.nextInt();
        coeff = new double[n+1];
        System.out.println("enter "+ (n+1) +" coefficients: ");
        for(int i=n; i>=0; i--)
            coeff[i]=sc.nextInt();
        
        modifiedBisection(-2.6,1.5);
        //System.out.println(function(3));
    }
}
