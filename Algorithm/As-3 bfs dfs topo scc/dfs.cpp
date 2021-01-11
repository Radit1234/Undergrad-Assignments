#include<bits/stdc++.h>
using namespace std;

vector< int > adj[1000];
int t, node, visited[1000] = {0}, discover_time[1000] , finish_time[1000];
int pred[1000];


void dfs_visit(int i){

    t += 1;
    discover_time[i] = t;
    visited[i] = 1;

    for(int j=0; j<adj[i].size(); j++){
        int v = adj[i][j];

        if(visited[v] == 0){
            pred[v] = i;
            dfs_visit(v);
        }
    }

    t += 1;
    finish_time[i] = t;
    printf("%d ", i);
}


void dfs(){

    for(int i=0; i<node ; i++)
    {
        visited[i] = 0;
        pred[i] = '-';
    }
    t = 0;
    for(int i=0; i< node ; i++){
        if(visited[i] == 0)
            dfs_visit(i);
    }
}



int main(){
    int edge;
    int x,y;
    cin>> node >> edge;

    for(int i=0; i<edge; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
    }

    cout<<"DFS traversal: "<<endl;

    dfs();



}
