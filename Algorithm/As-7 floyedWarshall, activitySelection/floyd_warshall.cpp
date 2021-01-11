#include<bits/stdc++.h>
using namespace std;

#define INF 65535
int v, dist[100][100], graph[100][100];


void print_solution(){
    printf("shortest distance between all pair of vertices: \n");

    for(int j=0; j<v; j++){
        printf("\t%d",j);
    }

    for(int i=0; i<v; i++){
            printf("\n%d",i);
        for(int j=0; j<v; j++){
            if(dist[i][j] == INF)
                printf("\tINF");
            else
                printf("\t%d",dist[i][j]);
        }
    }
}



void floydWarshall(){
    int pred[v][v];

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++){
            dist[i][j] = graph[i][j];
            pred[i][j] = i;
        }
    }

    for(int i=0; i<v; i++)
        dist[i][i] = 0;

    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){

                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }

    print_solution();
}


int main(){
    int edge,x,y,w;
    cin>>v>>edge;

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            graph[i][j] = INF;
        }
    }

    for(int i=0; i<edge; i++){
        cin>>x>>y>>w;
        graph[x][y] = w;
    }

    floydWarshall();
}
