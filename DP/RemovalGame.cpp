#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[505][505];

ll fn(vector<ll>& piles, int i, int j, bool turn) {
    if (i > j) 
        return 0;
    
    if (dp[i][j] != -1) 
        return dp[i][j];
    
    if (turn) { 
        ll a = piles[i] + fn(piles, i + 1, j, !turn);
        ll b = piles[j] + fn(piles, i, j - 1, !turn);
        return dp[i][j] = max(a, b);
    } else { 
        ll a = -piles[i] + fn(piles, i + 1, j, !turn);
        ll b = -piles[j] + fn(piles, i, j - 1, !turn);
        return dp[i][j] = min(a, b);
    }
}

int main() {
    ll n; cin >> n;
    vector<ll> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector< vector<ll>> table(n, vector<ll>(n, 0));

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            ll j = i + len - 1;

            ll x, y, z;
            x = (i + 2 <= j) ? table[i + 2][j] : 0;
            y = (i + 1 <= j - 1) ? table[i + 1][j - 1] : 0;
            z = (i <= j - 2) ? table[i][j - 2] : 0;

            table[i][j] = max(nums[i] + min(x, y), nums[j] + min(y, z));

        }
    }

    cout << table[0][n - 1] << endl;

}