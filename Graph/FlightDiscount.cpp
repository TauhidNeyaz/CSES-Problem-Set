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
typedef unordered_map<ll, vll> uG;
typedef unordered_map<ll, vector<pll>> wG;

const int inf = 1e9;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

vll dis, vis, path, cst;
map<string, int> mpp;

void SP(wG &G) {
    dis[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1}); 

    while (!pq.empty()) {
        pll cur = pq.top();
        pq.pop();

        if (vis[cur.se]) continue;
        vis[cur.se] = 1;

        for (auto &nbr : G[cur.se]) {
            
            if (dis[nbr.fi] > dis[cur.se] + nbr.se) {
                path[nbr.fi] = cur.se; 
                dis[nbr.fi] = dis[cur.se] + nbr.se; 
                pq.push({dis[nbr.fi], nbr.fi}); 
            }
        }
    }
}

void p_to_c(int node) {
    if (path[node] == -1) {
        return;
    }
    string s = to_string(path[node]) + to_string(node);
    cst.pb(mpp[s]);
    p_to_c(path[node]);
}

void Tauhid() {
    
    int V, E;
    cin >> V >> E;

    wG G;
    loop(i, 1, E) {
        int u, v, w;
        cin >> u >> v >> w;

        G[u].pb({v, w});
        string s = to_string(u) + to_string(v);
        mpp[s] = w;
    }

    dis.resize(V + 1, INF);
    vis.resize(V + 1, 0);
    path.resize(V + 1, -1);
    cst.clear(); 

    SP(G);
    p_to_c(V);
    ll sum = accumulate(all(cst), 0LL);
    ll mxx = *max_element(all(cst));
    ll ff = floor(mxx * 1.0 / 2.0);

    cout << (sum - mxx) + ff;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Tauhid();
    return 0;
}
