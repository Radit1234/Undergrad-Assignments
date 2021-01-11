#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int request[MAX];

int main()
{
    freopen("input.txt","r",stdin);

    int n,head,upper,lower,c_move = 0, x, y;
    string ans ;
    cin>>n;


    for(int i=0;i<n;i++)
        cin>>request[i];
    cin>>head;
    cout<<head;
    sort(request,request+n);

    upper = upper_bound(request,request+n,head) - request;
    lower = upper - 1;

    while(lower>=0 || upper<n)
    {
        if(lower>=0)
            x = abs(head - request[lower]);
        else
            x = INT_MAX;
        if(upper<n)
            y = abs(head - request[upper]);
        else
            y = INT_MAX;

        if(x>y)
        {
            c_move += y;
            head = request[upper];
            upper++;
        }
        else
        {
            c_move += x;
            head = request[lower];
            lower--;
        }
        //cout<<upper<<" "<<lower<<" "<<head<<endl;
        cout<<"-->"<<head;
    }

    cout<<endl<<endl;
    cout<<"Cylinder Movement: "<<c_move<<endl;
}

