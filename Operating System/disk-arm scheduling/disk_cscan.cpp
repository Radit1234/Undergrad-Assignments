#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int request[MAX];

int main()
{
    freopen("input.txt","r",stdin);

    int n,head,upper,lower,c_move = 0, x, y, n_head = 200 - 1;
    string ans ;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>request[i];
    cin>>head;
    cout<<head;
    sort(request,request+n);

    upper = upper_bound(request,request+n,head) - request;
    lower = upper - 1;

    for(int i=upper;i<n;i++)
    {
        cout<<"-->"<<request[i];
        c_move += abs(head - request[i]);
        head = request[i];
    }
    c_move += abs(head - n_head + n_head);
    head = 0;
    cout<<"-->"<<n_head<<"-->"<<head;

    for(int i=0;i<=lower;i++)
    {
        cout<<"-->"<<request[i];
        c_move += abs(head - request[i]);
        head = request[i];
    }
    cout<<endl<<endl;
    cout<<"Cylinder Movement: "<<c_move<<endl;
}


