static int coeff[];
    
    static int function_eval(int coeff[], int x){       
        int p[]= new int[coeff.length];
        int n = coeff.length - 1 ;
        
        for(int i = n; i>=0; i--){
            if(i==n)
                p[i]= coeff[i];
            else
            {
                p[i] = p[i+1]* x + coeff[i];               
            }
            //System.out.println(i+" "+p[i]);
        }
        return p[0];
    }
    
    public static void main(String args[]){
        int n,val;
        Scanner sc= new Scanner(System.in);
        n = sc.nextInt();
        coeff= new int[n+1];
        System.out.println("enter the coefficients: ");
        for(int i=n; i>=0; i--)
            coeff[i]=sc.nextInt();
        System.out.println("value: "+function_eval(coeff,2));
        
    }
