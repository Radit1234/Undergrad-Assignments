import java.util.Scanner;

public class BGauss {
    
    static double x[];
    
    public static void solve(double a[][], double b[]){
        int n= a.length;
        double[] temp = new double[n];
        for(int i=0; i<n-1; i++){
            double pivot = a[i][i];    
            double tempb = b[i];
            for(int j=0; j<temp.length; j++){
                temp[j] =a[i][j]/ pivot;
            }
            tempb /= pivot;
        
        for(int j=i+1; j<n; j++){
               
                double t = a[j][i];
                for(int k=0; k<n; k++){
                
                    a[j][k] = a[j][k] - ( t* temp[k]);
                    
                }
                
                    b[j] -= tempb*t; 
                
            }
        print(a,b);
        }
        backSubstitution(a,b);
    }
    
    public static void backSubstitution(double a[][],double b[]){
        int n= b.length-1;
        double sum;
        x = new double[n+1];
        x[n] = b[n]/a[n][n];
        for(int k=n-1; k>=0; k--){
            sum=0;
            for(int j=k+1; j<=n; j++)
                sum = sum+ a[k][j] * x[j];
            x[k] = (b[k] - sum)/a[k][k];
        }
        
        printValues(x);
    }
    
    public static void print(double a[][],double b[]){
        
        for(int i=0; i<a.length; i++){
            for(int j=0; j<a[i].length; j++){
                System.out.printf("%.3f\t",a[i][j]);
            }
            System.out.printf("%.3f\n",b[i]);
        }
    }
    
     public static void printValues(double a[]){
        int count=1;
        for(int i=0; i<a.length; i++){
            System.out.printf("x%d : %.3f\n",count++ ,a[i]);
        }
    }
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double a[][] = new double[n][n];
        double b[] = new double[n];
        for(int i=0; i<a.length; i++){
            for(int j=0; j<a[i].length; j++){
                a[i][j] = sc.nextDouble();
            }
            b[i] = sc.nextDouble();
        }
        solve(a,b);
    }    
}
