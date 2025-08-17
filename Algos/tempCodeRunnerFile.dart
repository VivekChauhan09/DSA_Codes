#include <bits/stdc++.h>
using namespace std;

struct Union {
    vector<int> parent;
    vector<int> treeSize;

    Union(int v) {
        parent.resize(v, -1);
        treeSize.resize(v, 1);
    }

    int findParent(int node) {
        if (parent[node] == -1) return node;
        return parent[node] = findParent(parent[node]);
    }

    bool join(int u, int v) {
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (uParent != vParent) {
            if (treeSize[uParent] < treeSize[vParent]) {
                parent[uParent] = vParent;
                treeSize[vParent] += treeSize[uParent];
            } else {
                parent[vParent] = uParent;
                treeSize[uParent] += treeSize[vParent];
            }
            return true;
        }
        return false;
    }
};

int kruskal(vector<vector<int>>& mat) {
    int n = mat.size();
    Union obj(n);
    vector<pair<int, pair<int, int>>> Edge;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] != 0) {
                Edge.push_back({mat[i][j], {i, j}});
            }
        }
    }

    sort(Edge.begin(), Edge.end());

    int Cost = 0;
    for (auto it : Edge) {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (obj.findParent(u) != obj.findParent(v)) {
            obj.join(u, v);
            Cost += w;
        }
    }

    return Cost;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    cout << "Minimum Spanning tree : " << kruskal(mat) << endl;
    return 0;
}
