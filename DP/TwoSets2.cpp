#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int mod = 1e9 + 7;

int fn(int n, int sum) {
    if (sum == 0) return 1; 
    if (sum < 0 || n == 0) return 0; 

    if (dp[n][sum] != -1) return dp[n][sum]; 

    dp[n][sum] = (fn(n - 1, sum - n) + fn(n - 1, sum)) % mod;
    return dp[n][sum];
}

int main() {
    int n; cin >> n;

    int sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << 0;
        return 0;
    }

    dp.resize(n + 1, vector<int>(sum / 2 + 1, -1));

    cout << (fn(n, sum / 2) * 1LL * 500000004) % mod; // Use modular multiplicative inverse for division by 2

    return 0;
}
