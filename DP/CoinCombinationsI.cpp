#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;


int main() {
    ll n, sums;
    cin >> n >> sums;
    vector<ll> nums(n);
    for (auto &i : nums) cin >> i;

    vector<ll> dp(sums + 1, 0);
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
