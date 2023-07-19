#include <bits/stdc++.h> 
#include<iostream>
#include<unordered_map>
using namespace std;
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1,1e9);
    dist[src]=0;

    for(int i=1;i<=n;i++){
        //traverse on edge list
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];

            if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
                dist[v]=dist[u]+wt;
            }
        }
    }
    //check for negaive cycle
    bool flag=0;

    for(int j=0;j<m;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];

        if(dist[u]!=1e9 && ((dist[u]+wt<dist[v]))){
            flag=1;
        }
    }
    if(flag==0){
        return dist[dest];
    }
    return -1;
}

int main(){
    int vertex=5;
    int edges=8;
    int src=1;
    int dest=5;
    vector<vector<int>> edge={{1,2,5},{1,3,2},{3,4,1},{1,4,6},{3,5,5},{4,5,2},{2,4,3},{2,5,7}};

    cout<<bellmonFord(vertex,edges,src,dest,edge)<<endl;

    return 0;
}