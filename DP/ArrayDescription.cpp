#include <bits/stdc++.h>
using namespace std;

#define ll long long

int mod = 1e9 + 7;
int dp[100005];

int fn(vector<ll>& nums, ll idx, ll val, ll m) {

    if (idx == nums.size()) return 1;
    if (val < 1 && val > m) return 0;

    if (nums[idx] != 0) {
        if (nums[idx] == val) {
            return fn(nums, idx + 1, val, m);
        } else {
            return 0;
        }
    }

    ll ans = 0;

    ans = fn(nums, idx + 1, val + 1, m) + 
            fn(nums, idx + 1, val - 1, m) + 
            fn(nums, idx + 1, val, m);
    
    return ans;
            

}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (auto &i : v) cin >> i;

    ll sum = 0;
    for (int val = 1; val <= m; ++val) {
        sum += (fn(v, 0, val, m) % mod);
    }

    cout << sum << endl;

    
}
