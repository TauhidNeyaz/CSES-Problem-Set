#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

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