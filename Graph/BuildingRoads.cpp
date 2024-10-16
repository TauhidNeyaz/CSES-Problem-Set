#include <bits/stdc++.h>
using namespace std;

vector<int> visited;

void dfs(unordered_map<int, vector<int>>& G, int node) {
    visited[node] = 1;
    for (auto &nbr : G[node]) {
        if (!visited[nbr]) {
            dfs(G, nbr);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    unordered_map<int, vector<int>> G;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector< pair<int, int>> roads;
    visited.resize(V+1, 0);
    int prev = -1;

    for (int node = 1; node <= V; ++node) {

        if (!visited[node]) {
            dfs(G, node);
            if (prev == -1) {
                prev = node;
            } else {
                roads.push_back({prev, node});
                prev = node;
            }
        }  
    }

    cout << roads.size() << endl;
    for (auto &p : roads) {
        cout << p.first << " " << p.second << endl;
    }

}