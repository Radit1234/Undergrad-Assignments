#include<bits/stdc++.h>
using namespace std;

stack<int> Stack;
vector< int > adj[1000];
int t, node, visited[1000] = {0}, discover_time[1000] , finish_time[1000];



void topologicalSortUtil(int i){

    t += 1;
    discover_time[i] = t;
    visited[i] = 1;

    for(int j=0; j<adj[i].size(); j++){
        int v = adj[i][j];

        if(visited[v] == 0){
            topologicalSortUtil(v);
        }
    }

    t += 1;
    finish_time[i] = t;
    Stack.push(i);


}


void topologicalSort(){

    for(int i=0; i<node ; i++)
    {
        visited[i] = 0;
    }
    t = 0;
    for(int i=0; i< node ; i++){
        if(visited[i] == 0)
            topologicalSortUtil(i);
    }


    cout<<"Topological Sort: "<<endl;
    while(Stack.empty() == false){
        cout<<Stack.top()<<" ";
        Stack.pop();
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

    topologicalSort();


}

