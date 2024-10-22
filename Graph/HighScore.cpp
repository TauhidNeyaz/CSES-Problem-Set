#include <bits/stdc++.h>

#define loop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(r); i >= (int)(l); --i)

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pp;
typedef vector<pp> vpp;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll INF = 1e18;
vector<ll> adj[2505], rev_adj[2505];
ll dist[2505];
bool vis[2505], rev_vis[2505];

void dfs(int node) {
    vis[node] = true;
    for (auto &nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr);
        }
    }
}

void rev_dfs(int node) {
    rev_vis[node] = true;
    for (auto &nbr : rev_adj[node]) {
        if (!rev_vis[nbr]) {
            rev_dfs(nbr);
        }
    }
}

void Tauhid() {
    
    fill(adj, adj + 2505, vector<ll>());
    fill(rev_adj, rev_adj + 2505, vector<ll>());
    fill(vis, vis + 2505, false);
    fill(rev_vis, rev_vis + 2505, false);
    
    int V, E;
    cin >> V >> E;

    vector<vector<ll>> G; 
    fill(dist, dist + V + 1, INF);
    dist[1] = 0;

    loop(i, 1, E) {
        ll u, v, c;
        cin >> u >> v >> c;

        G.pb({u, v, -c});
        adj[u].pb(v);
        rev_adj[v].pb(u);
    }

    dfs(1);
    rev_dfs(V);

    loop(i, 1, V) {
        for (auto &vec : G) {
            ll u = vec[0], v = vec[1], c = vec[2]; 
            if (dist[u] != INF && dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
            }
        }
    }

    loop(i, 1, V) {
        for (auto &vec : G) {
            ll u = vec[0], v = vec[1], c = vec[2]; 
            if (dist[u] != INF && dist[u] + c < dist[v]) {
                if (vis[v] && rev_vis[v]) {
                    cout << -1;
                    return;
                }
            }
        }
    }

    dist[V] != INF ? cout << -dist[V] : cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Tauhid();
    return 0;
}
