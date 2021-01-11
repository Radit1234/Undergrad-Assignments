#include <bits/stdc++.h>

using namespace std;

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*i+2;
}

void maxHeapify(int a[], int n ,int i){
    int largest;
    int l = left(i);
    int r = right(i);
    if(l< n && a[l]> a[i])
        largest = l;
    else
        largest = i;
    if(r< n && a[r]> a[largest])
        largest = r;
    if(largest != i){
        swap(a[i] , a[largest]);
        maxHeapify(a, n, largest);
    }
}

void build_maxHeap(int a[], int n){

    for(int i= (n/2)-1; i>=0; i--)
        maxHeapify(a, n, i);
}

void heapsort(int a[], int n){
    build_maxHeap(a, n);
    for(int i= n-1; i>=0; i--){
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

int main(){
    int a[]={4,1,6,0,9,2};
    int n= sizeof(a)/a[0];

    heapsort(a,n);
    cout<<"Sorted numbers are: "<<endl;
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}
