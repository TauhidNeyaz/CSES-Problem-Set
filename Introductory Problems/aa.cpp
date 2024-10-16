#include <bits/stdc++.h>
using namespace std;

int BFS(unordered_map<int, vector<int>>& G, unordered_map<int, vector<int>>& g, int node) {
    queue<int> que;
    que.push(node);

    int cnt = 0;

    unordered_set<int> vis;
    vis.insert(node);

    while (!que.empty()) {
        int curr = que.front();
        que.pop();

        if (!G.count(curr)) {
            for (auto &nbr : g[curr]) {
                if (!vis.count(nbr)) {
                    vis.insert(nbr);
                    que.push(nbr);
                    ++cnt;
                }
            }
        } else {
            for (auto &nbr : G[curr]) {
                if (!vis.count(nbr)) {
                    vis.insert(nbr);
                    que.push(nbr);
                }
            }
        }
    }

    return cnt;

}

int fn(vector<int>& A, vector<int>& B) {
    unordered_map<int, vector<int>> G, g;

    for (int i = 0; i < A.size(); ++i) {
        G[B[i]].push_back(A[i]);

        g[B[i]].push_back(A[i]);
        g[A[i]].push_back(B[i]);
    }

    return BFS(G, g, 0);

}

int main() {
    int n; cin >> n;
    vector<int> A(n-1), B(n-1);
    for (auto &i : A) cin >> i;
    for (auto &i : B) cin >> i;

    int ans = fn(A, B);

    cout << ans << endl;
}