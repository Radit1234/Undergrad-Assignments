#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int n,c[MAX][MAX],val[MAX], wt[MAX];

void knapsack(int maxWt){

    for(int i=0; i<=n; i++)
        c[i][0] = 0;
    for(int w=0; w<=maxWt; w++)
        c[0][w] = 0;

    for(int i=1; i<=n; i++){
        for(int w=1; w<=maxWt; w++){
            if(wt[i] > w)
                c[i][w] = c[i-1][w];
            else
                c[i][w] = max(c[i-1][w],c[i-1][w-wt[i]]+val[i]);
        }
    }
    cout<<"value: "<<c[n][maxWt]<<endl;
}

void itemPrint(int i, int w){
    if(i==0)
        return;
    if(c[i][w] > c[i-1][w]){
        itemPrint(i-1,w-wt[i]);
        cout<<i+1<<" ";
    }
    else
        itemPrint(i-1,w);
}


int main(){
    int maxWt = 10;
    n=4;
    for(int i=0; i<n; i++){
        cin>>wt[i]>>val[i];
    }

    knapsack(maxWt);
    itemPrint(n,maxWt);
}

