#include <bits/stdc++.h>
using namespace std;
 
int mod = 1e9+7;
 
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
 
    for (int i = 0; i < n; i++) {
        int x = coins[i];
        for (int j = x; j <= amount; j++) {
            dp[j] += (dp[j-x] % mod);
            dp[j] %= mod;
 
        }
    }
    return dp[amount];
}
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }
    cout << change(k, nums);
    return 0;
}