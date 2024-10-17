#include <bits/stdc++.h>
using namespace std;

vector<int> teams, visited;

bool bfs(unordered_map<int, vector<int>>& G, int node) {
    queue<int> que;
    que.push(node);
    teams[node] = 1;

    visited[node] = 1;
    while (!que.empty()) {
        int curr = que.front();
        que.pop();

        for (auto& nbr : G[curr]) {
            if (!visited[nbr]) {
                visited[nbr] = 1;
                teams[nbr] = !teams[curr];
                que.push(nbr);
            } else {
                if (teams[nbr] == teams[curr])
                    return false;
            }
        }
    }
    return true;
}

int main() {
    int pupils, friendship;
    cin >> pupils >> friendship;

    unordered_map<int, vector<int>> G;

    for (int i = 0; i < friendship; ++i) {
        int u, v;
        cin >> u >> v;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    teams.resize(pupils + 1, -1); 
    visited.resize(pupils + 1, 0);

    bool ans = true;
    for (int i = 1; i <= pupils; ++i) {
        if (visited[i] == 0) {
            if (!bfs(G, i)) {
                ans = false;
                break;
            }
        }
    }

    if (!ans) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 1; i <= pupils; ++i) {
            cout << teams[i] + 1 << " "; 
        }
        cout << endl;
    }

    return 0;
}
