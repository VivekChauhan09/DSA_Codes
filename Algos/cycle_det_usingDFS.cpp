#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and detect a cycle in an undirected graph.
bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
    vis[node] = 1; 
    // Visit adjacent nodes
    for(auto neighbour: adj[node]) {
        // Unvisited adjacent node
        if(!vis[neighbour]) {
            if(dfs(neighbour, node, vis, adj)) 
                return true; 
        }
        // Visited node but not a parent node
        else if(neighbour != parent) 
            return true; 
    }
    return false; 
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0}; 
    // For graph with connected components 
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(dfs(i, -1, vis, adj)) 
                return true; 
        }
    }
    return false; 
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<int> adj[V];

    cout << "Enter the edges (u v) for each edge:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
    }

    bool ans = isCycle(V, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}
