#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    char nums[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> nums[i][j];
        }
    }

    int mod = 1e9 + 7;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        if (nums[0][i] == '*') break;
        dp[0][i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i][0] == '*') break;
        dp[i][0] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (nums[i][j] == '*')
                dp[i][j] = 0;
            else 
                dp[i][j] = (dp[i-1][j] % mod + dp[i][j-1] % mod) % mod;
        }
    }

    cout << dp[n-1][n-1];
}
