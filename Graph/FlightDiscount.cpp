#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits>

#define loop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef unordered_map<ll, vector<pll>> wG;

const ll INF = 1e18;

vector<ll> temp, dis, rev_dis, vis;

void SP(wG &G, int node) {
    dis.assign(dis.size(), INF);
    vis.assign(vis.size(), 0);
    dis[node] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, node}); 

    while (!pq.empty()) {
        pll cur = pq.top();
        pq.pop();

        if (vis[cur.second]) continue;
        vis[cur.second] = 1;

        for (auto &nbr : G[cur.second]) {
            if (dis[nbr.first] > dis[cur.second] + nbr.second) {
                dis[nbr.first] = dis[cur.second] + nbr.second;
                pq.push({dis[nbr.first], nbr.first});
            }
        }
    }
}

void Tauhid() {
    int V, E;
    cin >> V >> E;

    wG G, revG;
    loop(i, 1, E) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        revG[v].push_back({u, w});
    }

    dis.resize(V + 1);
    rev_dis.resize(V + 1);
    vis.resize(V + 1);

    SP(G, 1);
    temp = dis;

    SP(revG, V);
    rev_dis = dis;

    ll ans = INF;

    for (auto &node : G) {
        int nd = node.first;
        vector<pll> eg = node.second;

        for (auto &p : eg) {
            ll div = p.second / 2;
            ans = min(ans, temp[nd] + rev_dis[p.first] + div);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Tauhid();
    return 0;
}
