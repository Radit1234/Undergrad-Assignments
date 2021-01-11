#include<bits/stdc++.h>
using namespace std;

int dist[100],n;

struct edge{
    int u,v,w;
};

vector<edge> e;

void printsp(){
    cout<<"detination\tdistance\n";
    for(int i=0; i<n; i++)
        cout<<i<<"\t"<<dist[i]<<endl;
}


void bellmanford(int s){
    for(int i=0; i<n; i++)
        dist[i] = 1000000000;
    dist[s] = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<e.size(); j++){
            edge eg = e[j];
            if(dist[eg.v] > dist[eg.u] + eg.w){
                dist[eg.v] = dist[eg.u] + eg.w;
            }
        }
    }
    printsp();
}

int main(){
    int edge_num;
    cin>>n>>edge_num;
    for(int i=0; i<edge_num; i++){
        edge newEdge;
        cin>>newEdge.u>>newEdge.v>>newEdge.w;
        e.push_back(newEdge);
    }
    bellmanford(0);
}
