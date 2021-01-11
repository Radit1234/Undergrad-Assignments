#include<bits/stdc++.h>
using namespace std;

int p[1000];

struct Edge{
    int u,v,w;

};

bool operator<(Edge a, Edge b){
    return a.w<b.w;
}

vector<Edge> e;

//finds the parent of a vertex

int find_(int x){
    if(p[x]==x)
        return x;
    return p[x] = find_(p[x]);
}

int kruskal(){

    sort(e.begin(),e.end());
    int size_ = e.size();
    int dis = 0;
    cout<<"\nMST edges: "<<endl;
    for(int i=0; i<size_ ; i++){
        if(find_(e[i].u) != find_(e[i].v)){
            p[p[e[i].u]] = p[e[i].v];               //parents of u becomes parent of v
            dis += e[i].w;
            cout<<e[i].u<<","<<e[i].v<<endl;
        }

    }
    cout<<"minimum cost: "<<dis;

}

int main(){

    int nodesNum,edgeNum,u,v,w;
    cout<<"Enter no of nodes and edges: ";
    cin>> nodesNum >>edgeNum;

    for(int i=1; i<=nodesNum; i++)
        p[i]= i;

    cout<<"Enter edge start vertex,end vertex and weight: "<<endl;
    for(int i=0; i<edgeNum; i++){
        Edge newEdge;
        cin>>newEdge.u >>newEdge.v >> newEdge.w;
        e.push_back(newEdge);
    }

    kruskal();


}



