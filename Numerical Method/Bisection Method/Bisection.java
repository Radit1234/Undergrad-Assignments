import java.util.Scanner;


public class Bisection {

    static double a3, a2, a1, a0;

    public static double function(double x){
        return a2*x*x+a1*x+a0;
    }

    public static double searchBracket(){
        return Math.sqrt(Math.pow((a1/a2),2)-2*(a0/a2));
    }

    public static void solution(){

        double x0, x1, x2, f0, f1, f2, root, e=0.001;
        x1= searchBracket();
        x2= -x1;
        f1= function(x1);
        f2= function(x2);

        if(f1==0)
            System.out.println("The root is : "+x1);
        if(f2==0)
            System.out.println("The root is : "+x2);
        else
        {
            while(true){
                x0=(x1+x2)/2;
                f0= function(x0);
                //System.out.println(f0+" "+f1+" "+f2);
                if(f0==0){
                    System.out.println("The root is : "+x0);
                    break;
                }

                if(f0*f2<0){
                    x1=x0;
                    f1=f0;
                }

                else{
                    x2=x0;
                    f2=f0;
                }

                if(Math.abs((x2-x1)/x2)< e){
                    System.out.println("The root is : "+(x1+x2)/2);
                    break;
            }
        }
    }
 }


    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        a2=1; a1=-4; a0=-10;
        solution();

    }
}
