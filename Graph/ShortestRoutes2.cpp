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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pp;
typedef vector<pp> vpp;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;


void FloydWarsal(vector<vll>& G) {
    int n = G.size();
    loop(k, 0, n-1) {
        loop(i, 0, n-1) {
            loop(j, 0, n-1) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

void Tauhid() {
    // write your code here...

    int V, E, Q;
    cin >> V >> E >> Q;

    vector<vll> G(V+1, vll(V+1, 1e18));
    loop(i, 1, E) {
        ll u, v, c;
        cin >> u >> v >> c;
        G[u][v] = min(c, G[u][v]);
        G[v][u] = min(c, G[u][v]);
    }

    loop(i, 0, V) {
        int j;
        loop(j, 0, V) {
            if (i == j) G[i][j] = 0;
        }
    }

    FloydWarsal(G);

    while (Q--) {
        int a, b; 
        cin >> a >> b;
        G[a][b] == 1e18 ? cout << -1 : cout << G[a][b];
        cout << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Tauhid();
    return 0;
}