#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS traversal from a given node
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
    vis[node] = 1;
    ls.push_back(node);
    // Traverse all its neighbours
    for (auto it : adj[node]) {
        // If the neighbour is not visited
        if (!vis[it]) {
            dfs(it, adj, vis, ls);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int start = 0;
    // Create a list to store DFS
    vector<int> ls;
    // Call DFS for starting node
    dfs(start, adj, vis, ls);
    return ls;
}

// Function to add an edge to the graph
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to print the DFS traversal result
void printAns(vector<int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    int V=5;
    vector<int> adj[V];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    vector<int> ans = dfsOfGraph(V, adj);
    printAns(ans);

    return 0;
}
