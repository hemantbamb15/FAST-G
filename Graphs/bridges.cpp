#include <bits/stdc++.h> 
#include<iostream>
#include<unordered_map>
using namespace std;

void dfs(int node,int parent,int & timer,vector<int>& disc,vector<int>&low, vector<vector<int>> &result,
unordered_map<int,list<int>> &adj, unordered_map<int,bool> &vis){
    vis[node]=true;
    disc[node]=low[node]=timer++;

    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,result,adj,vis);
            low[node]=min(low[node],low[nbr]);

            //check edge is bridge
            if(low[nbr]>disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            //back edge
            low[node]=min(low[node],disc[nbr]);
        }
    }
}




vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=0;

    vector<int> disc(v);
    vector<int> low(v);

    int parent=-1;
    unordered_map<int,bool> vis;

    for(int i=0;i<v;i++){
        disc[i]=-1;
        low[i]=-1;
    }

    vector<vector<int>> result;

    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,result,adj,vis);
        }
    }
    return result;

}

int main(){
    int vertex=5;
    int edges=5;
    vector<vector<int>> edge={{0,1},{1,2},{2,3},{3,4},{4,0}};

    vector<vector<int>> ans=findBridges(edge,vertex,edges);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}