#include <bits/stdc++.h>
using namespace std;

vector< vector<int>> memo;

int fn(int n, int m) {

    if (n == m)
        return 0;
    
    if (memo[n][m] != -1) return memo[n][m];

    int res = 1e9;

    for (int v = 1; v <= n - 1; ++v) {
        res = min(res, 1 + fn(v, m) + fn(n - v, m));
    }

    for (int h = 1; h <= m - 1; ++h) {
        res = min(res, 1 + fn(n, h) + fn(n, m - h));
    }

    return memo[n][m] = res;
}

int main() {
    int n, m;
    cin >> n >> m;

    memo.resize(n + 1, vector<int>(m + 1, -1));
    // cout << fn(n, m) << endl; gives TLE in 2 cases

    vector< vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {

            // alredy square
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }

            // vertical cut
            for (int v = 1; v <= i - 1; ++v) {
                dp[i][j] = min(dp[i][j], 1 + dp[v][j] + dp[i - v][j]);
            }

            // horizontal cut
            for (int h = 1; h <= j - 1; ++h) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][h] + dp[i][j - h]);
            }
        }
    }

    cout << dp[n][m] << endl;
}