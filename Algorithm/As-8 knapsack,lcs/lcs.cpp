#include<bits/stdc++.h>
#define MAX 100
using namespace std;

char x[MAX], y[MAX];
int i,j,m,n,c[MAX][MAX],b[MAX][MAX];

int lcs(){
    m = strlen(x);
    n = strlen(y);

    for(int i=0; i<=m; i++)
        c[i][0]=0;
    for(int i=0; i<=n; i++)
        c[0][i]=0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1]== y[j-1])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 1;           //from north west
            }

            else if(c[i-1][j]>= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 2;          //from north
            }

            else{
                c[i][j] = c[i][j-1];
                b[i][j] = 3;         //from west
            }

        }
    }
    return c[m][n];
}

void printLCS(int i, int j){
    if(i==0 || j==0)
        return;
    if(b[i][j]==1){
        printLCS(i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]==2)
        printLCS(i-1,j);
    else
        printLCS(i,j-1);
}

int main(){

    printf("Enter string 1: ");
    gets(x);
    printf("Enter string 2: ");
    gets(y);
    printf("%d\n", lcs());
    printLCS(m,n);
}
