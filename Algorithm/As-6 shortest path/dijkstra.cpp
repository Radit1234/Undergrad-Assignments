#include<bits/stdc++.h>
using namespace std;

int dist[100],n;

struct node{
    int at, cost;
    node(int _at, int _cost){
        at = _at;
        cost = _cost;
    }
};

bool operator<(node a, node b){
    return a.cost > b.cost;
}

struct edge{
    int v,w;
};

vector <edge> adj[100];

priority_queue <node> pq;

void printsp(){
    cout<<"detination\tdistance\n";
    for(int i=0; i<n; i++)
        cout<<i<<"\t\t"<<dist[i]<<endl;
}

void dijkstra(int s){
    for(int i=0; i<n; i++)
        dist[i] = 1000000000;
    dist[s] = 0;
    pq.push(node(s,0));

    while(!pq.empty()){

        node u = pq.top();
        pq.pop();

        if(u.cost != dist[u.at])
            continue;
        for(int i=0; i<adj[u.at].size(); i++){
                edge e = adj[u.at][i];
            if(dist[e.v] > u.cost + e.w){
                dist[e.v] = u.cost + e.w;
                pq.push(node(e.v,dist[e.v]));
            }
        }
    }
    printsp();
}


int main(){
    int e,x,y,z;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        edge newEdge;
        cin>>x>>newEdge.v>>newEdge.w;
        adj[x].push_back(newEdge);
    }
    dijkstra(0);
}
