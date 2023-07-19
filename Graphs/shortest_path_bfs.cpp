#include <bits/stdc++.h> 
#include<iostream>
#include<unordered_map>
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int,list<int>> adj;
	for(int i=0;i<m;i++){
		int u=edges[i].first;
		int v=edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
	queue<int> q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;

	while(!q.empty()){
		int front=q.front();
		q.pop();

		for(auto i:adj[front]){
			if(!visited[i]){
				visited[i]=true;
				parent[i]=front;
				q.push(i);
			}
		}
	}
	vector<int> ans;
	int currentNode=t;
	ans.push_back(t);

	while(currentNode!=s){
		currentNode=parent[currentNode];
		ans.push_back(currentNode);
	}

	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	int n=5;
	int m=5;
	int s=0;
	int t=3;
	vector<pair<int,int>> edges={{0,1},{1,2},{2,3},{3,4},{4,0}};
	vector<int> ans=shortestPath(edges,n,m,s,t);
	for(auto i:ans){
		cout<<i<<" ";
	}
	return 0;
}