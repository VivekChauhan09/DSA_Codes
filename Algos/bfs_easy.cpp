#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS traversal of the graph
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0}; 
    vis[0] = 1; 
    queue<int> q;
    q.push(0); 
    vector<int> bfs; 
    while (!q.empty()) {
        int node = q.front(); 
        q.pop(); 
        bfs.push_back(node); 
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1; 
                q.push(it); 
            }
        }
    }
    return bfs; 
}

// Function to add an edge to the graph
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to print the BFS traversal result
void printAns(vector<int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int V = 5;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector<int> ans = bfsOfGraph(V, adj);
    printAns(ans);

    return 0;
}
