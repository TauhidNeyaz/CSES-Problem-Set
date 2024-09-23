#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, totalCost;
    cin >> n >> totalCost;
    vector<int> cost(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(totalCost + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= totalCost; j++) {
            int wt = cost[i - 1];
            int page = pages[i - 1];  // Corrected this line

            int a = dp[i - 1][j];
            int b = (j >= wt ? dp[i - 1][j - wt] + page : 0);

            dp[i][j] = max(a, b);
        }
    }

    cout << dp[n][totalCost];
    return 0;
}
