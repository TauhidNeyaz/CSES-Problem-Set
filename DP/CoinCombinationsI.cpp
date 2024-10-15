#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;


ll solve(ll N, ll X, vector<ll>& coins)
{
   
    ll dp[X + 1] = {};
    dp[0] = 1;
    for (int i = 1; i <= X; i++) {
        for (int j = 0; j < N; j++) {
            if (coins[j] > i)
                continue;
            dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
        }
    }
    return dp[X];
}

int main() {
    ll n, sums;
    cin >> n >> sums;
    vector<ll> nums(n);
    for (auto &i : nums) cin >> i;
    // ll ans = solve(n, sums, nums);
    // cout << ans << endl;

    vector<int> dp(sums + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= sums; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= nums[j]) {
                dp[i] = (dp[i] + dp[i - nums[j]]) % mod;
            }
        }
    }

    cout << dp[sums] << endl;
}
