// BFS For Directed and Undirected Graphs


#include <bits/stdc++.h> 
#include<iostream>
#include<unordered_map>
using namespace std;

void prepareAdjList_directed(unordered_map<int, set<int>>  &adjList,vector<pair<int,int>>&edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adjList[u].insert(v);
  
    }

  
}
void prepareAdjList_undirected(unordered_map<int, set<int>>  &adjList,vector<pair<int,int>>&edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }

  
}


void bfs(unordered_map<int,set<int>>& adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        ans.push_back(frontNode);
        //traverse all neighbours of frontNode

        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int, set<int>>  adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdjList_directed(adjList,edges);

      //traverse all components of a graph

      for(int i=0;i<vertex;i++){
          if(!visited[i]){
              bfs(adjList,visited,ans,i);
          }
      }
      return ans;
}

int main(){
    int vertex=5;
    vector<pair<int,int>> edges={{0,1},{1,2},{2,3},{3,4},{4,0}};
    vector<int> ans=BFS(vertex,edges);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}