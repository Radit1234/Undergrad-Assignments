#include<bits/stdc++.h>
using namespace std;

int a[100];

void exchange(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int p, int r){
    int x = a[r];
    int i = p-1;
    for(int j=p; j<=r-1; j++){
        if(a[j]<=x)
        {
            i++;
            exchange(a[i], a[j]);
        }
    }
    exchange(a[i+1],a[r]);
    return i+1;
}

void quicksort(int a[], int p, int r){
    if(p<r){
        int q= partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int main(void){
    int n;
    cout<<"how many numbers: ";
    cin>>n;
    cout<<"enter "<<n<<" numbers: "<<endl;
    for(int i=0; i<n; i++)
        cin>>a[i];

    quicksort(a,0,n-1);

    cout<<"sorted numbers: "<<endl;
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}
