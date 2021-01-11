import java.util.Scanner;

public class GaussJordan {
    
    public static void solve(double a[][], double b[]){
        int n = a.length;
        
        double pivot;
        for(int i=0; i<n ;i++){
            pivot = a[i][i];
            
            for(int j=0; j<a[i].length; j++){
                a[i][j] /= pivot;
            }
            b[i] /= pivot;
            
            for(int j=0; j<n; j++){
                if(j!= i){
                    double temp = a[j][i];
                for(int k=0; k<n; k++){
                
                    a[j][k] = a[j][k] - ( temp* a[i][k]);
                    
                }
                if(j!= i)
                    b[j] -= b[i]*temp; 
                }
            }
            print(a,b);
            
        }
        
        printValues(b);
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
