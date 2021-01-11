#include<bits/stdc++.h>
using namespace std;
#define MAX 100

struct process{
    int id;
    int allocation[MAX];
    int _max[MAX];
    int need[MAX];
    //bool complete = false;
}processes[MAX];

int n , r , totalresource[MAX] , available[MAX];
bool complete[MAX] = {false};

void input()
{
    freopen("input1.txt","r",stdin);
    //cout<<"enter number of process: "<<endl;
    cin>>n;
    //cout<<"enter number of r: "<<endl;
    cin>>r;

    for(int i=0;i<r;i++)
    {
        //cout<<"enter total value of resource "<<i<<" : "<<endl;
        cin>>totalresource[i];
    }

    for(int i=0;i<r;i++)
    {
        //cout<<"enter available value of resource "<<i<<" : "<<endl;
        cin>>available[i];
    }

    for(int i=0;i<n;i++)
    {
        //cout<<"process "<<i<<endl;

        processes[i].id = i;

        for(int j=0;j<r;j++)
        {
            //cout<<"enter allocated value of resource "<<j<<" : "<<endl;
            cin>>processes[i].allocation[j];
            //cout<<processes[i].allocation[j]<<endl;
        }

        for(int j=0;j<r;j++)
        {
            //cout<<"enter max value of resource "<<j<<" : "<<endl;
            cin>>processes[i]._max[j];
            processes[i].need[j] =  processes[i]._max[j] -  processes[i].allocation[j];
        }

    }

}

void banker()
{
    for(int k=0;k<n;k++)
    {

        for(int i=0;i<n;i++)
        {
            if(!complete[i])
            {
                bool check = true;
                for(int j=0;j<r;j++)
                    check = check & (processes[i].need[j] <= available[j]);

                if(check)
                {
                    cout<<"P"<<processes[i].id<<endl;
                    complete[i] = true;
                    for(int j=0;j<r;j++)
                        available[j] += processes[i].allocation[j];
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(!complete[i])
            cout<<"process "<<i <<"needs additional r"<<endl;
    }
}


int main()
{
    input();
    banker();
}
