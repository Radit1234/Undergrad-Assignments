#include<bits/stdc++.h>
using namespace std;

vector< int > adj[1000];
int t, node, visited[1000] = {0}, dis[1000] = {0} ;
int pred[1000] = {-1};


void bfs(int s){
    queue <int> q;
    visited[s] = 1;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        printf("%d ", u);
        for(int i=0; i< adj[u].size(); i++){
                int v = adj[u][i];
            if(visited[v] == 0){

                visited[v] = 1;
                dis[v] = dis[u] + 1;
                pred[v] = u;
                q.push(v);
            }
        }
        visited[u] = 1;
    }
}


int main(){
    int edge;
    int x,y;
    cin>> node >> edge;

    for(int i=0; i<edge; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<"BFS traversal: "<<endl;
    bfs(1);

}
