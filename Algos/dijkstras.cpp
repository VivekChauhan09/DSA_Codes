#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest distance of all the vertices
// from the source vertex S.
vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int S) {
    set<pair<int, int>> st; // To store {distance, node}
    vector<int> dist(V, 1e9); // To store distances from the source

    st.insert({0, S}); // Insert the source with distance 0
    dist[S] = 0; // Distance to the source is 0

    while (!st.empty()) {
        auto it = *(st.begin()); // Get the node with the smallest distance
        int node = it.second;
        int dis = it.first;
        st.erase(it); // Remove it from the set

        for (auto it : adj[node]) { // Iterate through adjacent nodes
            int adjNode = it.first; // Destination vertex
            int edgW = it.second; // Weight of the edge

            if (dis + edgW < dist[adjNode]) { // If a shorter path is found
                if (dist[adjNode] != 1e9)
                    st.erase({dist[adjNode], adjNode}); // Remove old distance

                dist[adjNode] = dis + edgW; // Update distance
                st.insert({dist[adjNode], adjNode}); // Insert new distance
            }
        }
    }
    return dist; // Return the shortest distances
}

int main() {
    int V, E, S;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the source vertex: ";
    cin >> S;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Uncomment this line if the graph is undirected
    }

    vector<int> res = dijkstra(V, adj, S);

    cout << "Shortest distances from source vertex " << S << " to all vertices:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << res[i] << endl;
    }

    return 0;
}
