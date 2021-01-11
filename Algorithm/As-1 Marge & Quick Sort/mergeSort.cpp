#include<iostream>
using namespace std;

int a[100];

void merge(int a[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int left[n1 + 1];
    int right[n2 + 1];
    for(int i=0 ; i<n1 ; i++)
        left[i]= a[p+i];
    for(int j=0 ; j<n2 ; j++)
        right[j]= a[q+1+j];
    left[n1]= 65535;
    right[n2]= 65535;
    int i=0;
    int j=0;
    for(int k = p ; k <= r; k++){
        if(left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
    }
}

void mergeSort(int a[], int p ,int r){
    if(p<r){
        int q =(p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        merge(a,p,q,r);
    }
}

int main(){
    int n;
    cout<<"how many numbers: ";
    cin>>n;
    cout<<"enter "<<n<<" numbers: "<<endl;
    for(int i=0; i<n; i++)
        cin>>a[i];

    mergeSort(a, 0 , n-1);

    cout<<"sorted numbers: "<<endl;
    for(int i=0; i< n ; i++)
        cout<<a[i]<<" ";
}
