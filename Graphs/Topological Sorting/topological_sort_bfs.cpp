#include <bits/stdc++.h> 
#include<iostream>
#include<unordered_map>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

   vector<int> indegree(v);

   for(auto i:adj){
       for(auto j: i.second){
           indegree[j]++;
       }
   }

   //0 indegree walo ko push krdo

   queue<int> q;
   for(int i=0;i<v;i++){
       if(indegree[i]==0){
           q.push(i);
       }
   }
    vector<int> ans;

    while(!q.empty()){
        int front=q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}

int main(){
    int v=5;
    int e=5;
    vector<vector<int>> edges={{0,1},{1,2},{2,3},{3,4},{4,0}};
    vector<int> ans=topologicalSort(edges,v,e);

    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}