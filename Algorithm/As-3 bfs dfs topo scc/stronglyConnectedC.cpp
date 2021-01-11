#include<bits/stdc++.h>
using namespace std;

stack<int> Stack;
vector< int > adj[1000];
vector< int > transposeAdj[1000];

int t, node, visited[1000] = {0};


void computeFinishTime(int i){

    visited[i] = 1;

    for(int j=0; j<adj[i].size(); j++){
        int v = adj[i][j];

        if(visited[v] == 0){
            computeFinishTime(v);
        }
    }

    Stack.push(i);

}


void dfs_visit(int i, vector< int > adj[]){

    visited[i] = 1;
    cout<<i<<" ";

    for(int j=0; j<adj[i].size(); j++){
        int v = adj[i][j];

        if(visited[v] == 0){
            dfs_visit(v,adj);
        }
    }
}

void getTranspose(){

    for(int i=0 ; i< node; i++){
            vector< int > :: iterator it;
        for(it = adj[i].begin(); it != adj[i].end(); it++)
        {
            transposeAdj[*it].push_back(i);
        }
    }
}


void printComponents(){
    int count = 1;
    for(int i=0; i<node ; i++)
    {
        visited[i] = 0;
    }

    for(int i=0; i< node ; i++){
        if(visited[i] == 0)
            computeFinishTime(i);
    }

    getTranspose();

    for(int i=0; i<node ; i++)
    {
        visited[i] = 0;
    }


    while(!Stack.empty()){
        int v = Stack.top();
        Stack.pop();

        if(visited[v] == 0){
            printf("%d : ",count++);
            dfs_visit(v, transposeAdj);
            cout<<endl;
        }
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

    printComponents();


}


