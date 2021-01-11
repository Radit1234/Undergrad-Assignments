#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> PII;
bool marked[1000];
int par[1000];
vector <PII> adj[1000];

void prim(int x, int nodes)
{
    priority_queue<PII, vector<PII>, greater<PII> > q;
    int y;
    int minDis = 0;
    PII p;
    par[x] = 0;
    q.push(make_pair(0, x));

    while(!q.empty())
    {
        // Select the edge with minimum weight
        p = q.top();
        q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;

        minDis += p.first;
        marked[x] = true;

        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false){
                q.push(adj[x][i]);
                par[y] = x;
                }
        }

    }
    cout<<"\nMST edges: "<<endl;
    for(int i=1; i<nodes; i++){
        if(par[i] != 0)
            cout<<par[i]<<","<<i<<endl;
    }
    cout<<"minimum cost: "<<minDis;
}

int main()
{
    int nodes, edges,w, x, y;
    cout<<"Enter no of nodes and edges: ";
    cin >> nodes >> edges;
    cout<<"Enter edge start vertex,end vertex and weight: "<<endl;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(w, y));
        adj[y].push_back(make_pair(w, x));
    }

    prim(1,nodes);

}
