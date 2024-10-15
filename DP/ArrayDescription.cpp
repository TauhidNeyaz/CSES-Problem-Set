#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool valid(ll x, ll m) {
    return x > 0 && x <= m;
}
int mod = 1e9 + 7;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (auto &i : v) cin >> i;

    vector< vector<ll>> dp(n + 1, vector<ll>(m + 1));
    // dp[i][j] = numsber of way to build a prefix array of size i such that
    // the last element of prefix is k

    // base case
    for (int i = 1; i <= m; ++i) {
        if (v[0] == 0 || v[0] == i) {
            dp[1][i] = 1;
        }
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {

            if (v[i-1] != 0 && v[i-1] != j) {
                dp[i][j] = 0;
                continue;
            }
            // diif is atmost 1, so (j - 1, j, j + 1)
            for (ll prev = j - 1; prev <= j + 1; ++prev) {
                if (!valid(prev, m))
                    continue;
                
                dp[i][j] = (dp[i][j] + (dp[i-1][prev]) % mod);
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans = (ans + dp[n][i]) % mod;
    }

    cout << ans << endl;
}
