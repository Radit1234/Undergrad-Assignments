#include<bits/stdc++.h>

using namespace std;
#define MAX 1000

int request[MAX], visited[MAX];

int main()
{
    freopen("input.txt","r",stdin);

    int n,head,lower,upper,c_move = 0;
    string ans ;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>request[i];
    cin>>head;
    cout<<head;
    //sort(request,request+n);

    upper = upper_bound(request,request+n,head) - request;
    //lower = upper - 1;
    cout<<upper<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"-->"<<request[i];
        c_move += abs(head - request[i]);
        head = request[i];
    }

    cout<<endl;
    cout<<"Cylinder Movement: "<<c_move<<endl;
}
