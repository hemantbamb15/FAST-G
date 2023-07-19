#include <bits/stdc++.h> 
#include<iostream>
#include<unordered_map>
using namespace std;

bool checkCycleDFS(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsvisited,unordered_map<int,list<int>>&adj){
  visited[node]=true;
  dfsvisited[node]=true;

  for(auto neighbour:adj[node]){
    if(!visited[neighbour]){
      bool cycleDetected=checkCycleDFS(neighbour,visited,dfsvisited,adj);
      if(cycleDetected){
        return true;
      }
    }
    else if(dfsvisited[neighbour]){
      return true;
    }
  }
  dfsvisited[node]=false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  //create adj list

  unordered_map<int,list<int>>adj;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adj[u].push_back(v);
  }
  //call dfs

  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsvisited;



  for(int i=1;i<=n;i++){
    if(!visited[i]){
      bool cycleFound=checkCycleDFS(i,visited,dfsvisited,adj);
      if(cycleFound){
        return true;
      }
    }
  }
  return false;
}

int main(){
  int vertex=5;
  vector<pair<int,int>> edges={{1,2},{2,3},{3,4},{4,5},{5,2}};

  cout<<detectCycleInDirectedGraph(vertex,edges)<<endl;
  return 0;
}