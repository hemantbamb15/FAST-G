#include <bits/stdc++.h> 
#include<iostream>
#include<unordered_map>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    // Write your code here.

    unordered_map<int, list<pair<int,int>>> adj;

    for(int i=0;i<g.size();i++){
         int u=g[i].first.first;
         int v=g[i].first.second;
         int w=g[i].second;

         adj[u].push_back(make_pair(v,w));
         adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0;i<=n;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;

    key[1]=0;
    parent[1]=-1;
    pq.push(make_pair(0,1));
        while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(mst[u]==true){
            continue;
        }

        mst[u]=true;

        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if (mst[v] == false && w < key[v]) {
               key[v] = w;
              pq.push(make_pair(key[v], v));
               parent[v] = u;
            
            }
        
        }
    }
    vector<pair<pair<int,int>,int>> result;

    for(int i=2;i<=n;i++){
        result.push_back(make_pair(make_pair(parent[i],i),key[i]));
    }
    return result;
}

// ##Method 2: (less efficient)


#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    // Write your code here.

    unordered_map<int, list<pair<int,int>>> adj;

    for(int i=0;i<g.size();i++){
         int u=g[i].first.first;
         int v=g[i].first.second;
         int w=g[i].second;

         adj[u].push_back(make_pair(v,w));
         adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0;i<=n;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }

    key[1]=0;
    parent[1]=-1;

    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        int u;

    // find the min wali node
        for(int v=1;v<=n;v++){
            if(mst[v]==false &&key[v]<mini){
                u=v;
                mini=key[v];
            }
        }
        mst[u]=true;

        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if (mst[v] == false && w < key[v]) {
               key[v] = w;
               parent[v] = u;
            
            }
        
        }
    }
    vector<pair<pair<int,int>,int>> result;

    for(int i=2;i<=n;i++){
        result.push_back(make_pair(make_pair(parent[i],i),key[i]));
    }
    return result;
}

int main(){
    int n=5;
    int m=7;
    vector<pair<pair<int,int>,int>> g;
    g.push_back(make_pair(make_pair(1,2),2));
    g.push_back(make_pair(make_pair(1,3),6));
    g.push_back(make_pair(make_pair(1,4),5));
    g.push_back(make_pair(make_pair(2,3),8));
    g.push_back(make_pair(make_pair(3,4),9));
    g.push_back(make_pair(make_pair(2,5),3));
    g.push_back(make_pair(make_pair(3,5),4));

    vector<pair<pair<int,int>,int>> result=calculatePrimsMST(n,m,g);

    for(int i=0;i<result.size();i++){
        cout<<result[i].first.first<<" "<<result[i].first.second<<" "<<result[i].second<<endl;
    }
    return 0;
}

    