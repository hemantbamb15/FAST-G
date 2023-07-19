#include <bits/stdc++.h> 
#include<iostream>
#include<unordered_map>
using namespace std;


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
   // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first-1;
        int v=edges[i].second-1;

        adj[u].push_back(v);
    }

   vector<int> indegree(n);

   for(auto i:adj){
       for(auto j: i.second){
           indegree[j]++;
       }
   }

   //0 indegree walo ko push krdo

   queue<int> q;
   for(int i=0;i<n;i++){
       if(indegree[i]==0){
           q.push(i);
       }
   }
    // vector<int> ans;
    int count=0;

    while(!q.empty()){
        int front=q.front();
        q.pop();

        // ans.push_back(front);
        count++;

        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    // return ans;
    // cout<<count<<endl;
    if(count==n){
      return false;
    }
    else{
      return true;
    }
  
}

int main(){
    int vertex=5;
    vector<pair<int,int>> edges={{1,2},{2,3},{3,4},{4,5},{5,1}};

    cout<<detectCycleInDirectedGraph(vertex,edges)<<endl;

    return 0;
}