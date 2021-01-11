#include<bits/stdc++.h>
using namespace std;
#define N 100000

vector<int> graph[N];
vector<int> graph2[N];
vector<int> cycles[N];
set<int> s;

int color[N], par[N], mark[N] , priority[N] , toDelete[N]= {0};
int cyclenumber = 0 , edges , n;

void dfs_cycle(int u, int p)
{
    if(color[u] == 2)
        return;
    if(color[u] == 1)
    {
        cyclenumber++;
        int cur = p;
        mark[cur] = cyclenumber;
        cout<<cyclenumber<<endl;
        while(cur != u)
        {
            cur = par[cur];
            mark[cur] = cyclenumber;
        }
        return;
    }
    par[u] = p;
    color[u] = 1;

    for(auto v : graph[u])
    {
        if(v == par[u]) continue;
        dfs_cycle(v,u);
    }
    color[u] = 2;
}

void printGraph()
{

    cout<<cyclenumber<<endl;
    for(int i=1;i<=100;i++)
    {
        if(mark[i] != 0)
            cycles[mark[i]].push_back(i);
    }

    for(int i=1; i<=cyclenumber;i++)
    {
        int leastp = INT_MAX , least = -1;
        cout<<"Cycle Number: "<<i<<" : ";
        //cout<<"size : "<<cycles[i].size()<<endl;
        for(auto x : cycles[i]){
            cout<<(char)x<<" ";
            if(priority[x] < leastp) leastp = priority[x] , least = x;
        }
        toDelete[least] = 1;
        cout<<endl;
    }
/*
    cout<<"new graph after deleting the low priority process of the cycle: "<<endl;
    for(int i=1;i<=100;i++)
    {
        if(s.count(i)<1)
            continue;
        if(toDelete[i])
            continue;
        for(auto y : graph[i])
        {
            if(toDelete[y]) continue;
            graph2[i].push_back(y);
            graph2[y].push_back(i);
            cout<<(char)y<<"---"<<(char)i<<endl;
        }
    }
*/
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char a,b;
    int x;

    cin>>n>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>a>>b;
        s.insert(a);
        s.insert(b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
/*
    for(int i=1;i<=n;i++)
    {
        //cout<<"Enter process and priority of the process "<<i<<" : "<<endl;
        cin>>a>>x;
        priority[a] = x;
    }
*/
    dfs_cycle('A',0);
    printGraph();

}



