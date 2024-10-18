#include <bits/stdc++.h>
using namespace std;

vector<int> visited, parent;
int cycle, head;
stack<int> stk;

bool bfs(unordered_map<int, vector<int>>& G, int node) {
    queue<int> que;
    que.push(node);
    visited[node] = 1;

    while (!que.empty()) {
        int curr = que.front();
        que.pop();

        for (auto &nbr : G[curr]) {
      
            if (visited[nbr] && nbr != parent[curr]) {
                cycle = curr;
                head = nbr;
                return true;
            }

            if (!visited[nbr]) {
                visited[nbr] = 1; 
                parent[nbr] = curr;
                que.push(nbr);
            }
        }
    }

    return false;
}

void path() {
    int idx = cycle;
    stk.push(cycle);
    while (idx != head) {
        stk.push(parent[idx]);
        idx = parent[idx];
    }
}

// Main function
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

    visited.resize(V + 1, 0);
    parent.resize(V + 1, -1);

    bool foundCycle = false;
    
    for (int node = 1; node <= V; ++node) {
        if (!visited[node]) {
            if (bfs(G, node)) {
                foundCycle = true;
                break;
            }
        }
    }

    if (!foundCycle) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    path();

    for (auto &i : parent) cout << i << " ";

    // cout << head << " ";
    // while (!stk.empty()) {
    //     cout << stk.top() << " ";
    //     stk.pop();
    // }
    // cout << head << endl;

    return 0;
}
