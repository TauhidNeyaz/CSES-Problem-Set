#include <bits/stdc++.h>

#define loop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(r); i >= (int)(l); --i)

#define pb push_back
#define fi first
#define se second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size())

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pp;
typedef vector<pp> vpp;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
typedef pair<ll, ll> pll;

unordered_map<int, vpp> G;
vll costs;
vi vis;

void bfs() {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    costs[1] = 0;


    while (!pq.empty()) {
        pll cur = pq.top();
        pq.pop();

        ll current_node = cur.se;
        ll current_cost = cur.fi;

        if (vis[current_node]) continue;;
        vis[current_node] = 1;

        for (auto &nbr : G[current_node]) {
            ll neighbor_node = nbr.fi;
            ll edge_cost = nbr.se;

            if (costs[neighbor_node] > current_cost + edge_cost) {
                costs[neighbor_node] = current_cost + edge_cost;
                pq.push({costs[neighbor_node], neighbor_node});
            }
        }
    }
}


void Tauhid() {
    // write your code here...

    ll V, E;
    cin >> V >> E;

    ll i;
    loop(i, 1, E) {
        ll v, u, c;
        cin >> u >> v >> c;
        G[u].pb({v, c});
        // G[u].pb({v, c});
    }
    costs.resize(V + 1, 1e18);
    vis.resize(V+1, 0);

    bfs();
    i = 1;
    loop(i, 1, V) {
        cout << costs[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Tauhid();
    return 0;
}