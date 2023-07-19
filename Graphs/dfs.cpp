#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node,unordered_map<int,bool> &visited, unordered_map<int,list<int>>&adj, vector<int>&component){
    component.push_back(node);
    visited[node]=true;

    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,component);
        }
    }
}





vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here

    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);


    }
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }

    }
    return ans;
}

int main(){
    int vertex=5;
    int edges=5;
    vector<vector<int>> edge={{0,1},{1,2},{2,3},{3,4},{4,0}};

    vector<vector<int>> ans=depthFirstSearch(vertex,edges,edge);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}