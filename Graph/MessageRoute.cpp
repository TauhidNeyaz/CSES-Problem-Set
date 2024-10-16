#include <bits/stdc++.h>
using namespace std;

vector<int> path, visited;
stack<int> stk;

bool bfs(unordered_map<int, vector<int>>& G, int src, int dst) {
    queue<int> que;
    que.push(src);
    visited[src] = 1;

    while (!que.empty()) {
        int node = que.front();
        que.pop();

        if (node == dst) return true;

        for (auto &nbr : G[node]) {
            if (!visited[nbr]) {
                visited[nbr] = 1;
                path[nbr] = node;
                que.push(nbr);
            }
        }
    }
    return false;
}

void makePath(int src, int dst) {
    while (dst != src) {
        stk.push(path[dst]);
        dst = path[dst];
    }
}

int main() {
    int computer, connection;
    cin >> computer >> connection;

    unordered_map<int, vector<int>> G;
    for(int i = 0; i < connection; ++i) {
        int a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }
    path.resize(computer + 1, 0);
    visited.resize(computer + 1, 0);

    bool ans = bfs(G, 1, computer);

    if (!ans) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        makePath(1, computer);
        cout << stk.size() + 1 << endl;
        while (!stk.empty()) {
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << computer;
    }
}