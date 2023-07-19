// The second implementation is time complexity wise better but is really complex as we have implemented our own priority queue. The First implementation is simpler as it uses STL. The issue with third implementation is, it uses set which in turn uses Self-Balancing Binary Search Trees. For Dijkstra’s algorithm, it is always recommended to use heap (or priority queue) as the required operations (extract minimum and decrease key) match with speciality of heap (or priority queue). However, the problem is, priority_queue doesn’t support decrease key. To resolve this problem, do not update a key, but insert one more copy of it. So we allow multiple instances of same vertex in priority queue. This approach doesn’t require decrease key operation and has below important properties.

// Whenever distance of a vertex is reduced, we add one more instance of vertex in priority_queue. Even if there are multiple instances, we only consider the instance with minimum distance and ignore other instances.
// The time complexity remains O(ELogV)) as there will be at most O(E) vertices in priority queue and O(Log E) is same as O(Log V)

#include <bits/stdc++.h> 
#include<iostream>
#include<unordered_map>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices);

    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }

    set<pair<int,int>> st;
    
    dist[source]=0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        auto top=*(st.begin());

        int nodeDistance=top.first;
        int topNode=top.second;

        st.erase(st.begin());

        for(auto neighbour:adj[topNode]){
            if(nodeDistance + neighbour.second<dist[neighbour.first]){
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));

                if(record!=st.end()){
                    st.erase(record);
                }
                dist[neighbour.first]=nodeDistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist;
}

int main(){
    int vertex=5;
    int edges=7;
    vector<vector<int>> edge={{0,1,4},{0,2,8},{1,2,8},{1,3,11},{2,3,7},{2,4,2},{3,4,9}};

    vector<int> ans=dijkstra(edge,vertex,edges,0);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//Method 2 using priority queue

// Program to find Dijkstra's shortest path using
// priority_queue in STL

// #include <bits/stdc++.h>
// using namespace std;
 
// // iPair ==> Integer Pair
// typedef pair<int, int> iPair;
 
// // To add an edge
// void addEdge(vector<pair<int, int> > adj[], int u, int v,
//              int wt)
// {
//     adj[u].push_back(make_pair(v, wt));
//     adj[v].push_back(make_pair(u, wt));
// }
 
// // Prints shortest paths from src to all other vertices
// void shortestPath(vector<pair<int, int> > adj[], int V,
//                   int src)
// {
//     // Create a priority queue to store vertices that
//     // are being preprocessed. This is weird syntax in C++.
    
//     priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
 
//     // Create a vector for distances and initialize all
//     // distances as infinite (INF)
//     vector<int> dist(V, INT_MAX);
 
//     // Insert source itself in priority queue and initialize
//     // its distance as 0.
//     pq.push(make_pair(0, src));
//     dist[src] = 0;
 
//     /* Looping till priority queue becomes empty (or all
//     distances are not finalized) */
//     while (!pq.empty()) {
//         // The first vertex in pair is the minimum distance
//         // vertex, extract it from priority queue.
//         // vertex label is stored in second of pair (it
//         // has to be done this way to keep the vertices
//         // sorted distance (distance must be first item
//         // in pair)
//         int u = pq.top().second;
//         pq.pop();
 
//         // Get all adjacent of u.
//         for (auto x : adj[u]) {
//             // Get vertex label and weight of current
//             // adjacent of u.
//             int v = x.first;
//             int weight = x.second;
 
//             // If there is shorted path to v through u.
//             if (dist[v] > dist[u] + weight) {
//                 // Updating distance of v
//                 dist[v] = dist[u] + weight;
//                 pq.push(make_pair(dist[v], v));
//             }
//         }
//     }
 
//     // Print shortest distances stored in dist[]
//     printf("Vertex Distance from Source\n");
//     for (int i = 0; i < V; ++i)
//         printf("%d \t\t %d\n", i, dist[i]);
// }
 
// // Driver program to test methods of graph class
// int main()
// {
//     int V = 9;
//     vector<iPair> adj[V];
 
//     // making above shown graph
//     addEdge(adj, 0, 1, 4);
//     addEdge(adj, 0, 7, 8);
//     addEdge(adj, 1, 2, 8);
//     addEdge(adj, 1, 7, 11);
//     addEdge(adj, 2, 3, 7);
//     addEdge(adj, 2, 8, 2);
//     addEdge(adj, 2, 5, 4);
//     addEdge(adj, 3, 4, 9);
//     addEdge(adj, 3, 5, 14);
//     addEdge(adj, 4, 5, 10);
//     addEdge(adj, 5, 6, 2);
//     addEdge(adj, 6, 7, 1);
//     addEdge(adj, 6, 8, 6);
//     addEdge(adj, 7, 8, 7);
 
//     shortestPath(adj, V, 0);
 
//     return 0;
// }


// The time complexity of Dijkstra’s algorithm using a priority queue implemented with a binary heap is O(Elog(V)), where E is the number of edges and V is the number of vertices in the graph.

// The space complexity of this implementation is O(V+E), where V is the number of vertices and E is the number of edges. 




