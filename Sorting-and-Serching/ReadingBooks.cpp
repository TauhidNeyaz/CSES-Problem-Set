#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;
    vector<ll> nums(n);
    for (auto &i : nums) cin >> i;
    sort(nums.begin(), nums.end());

    ll sum = accumulate(nums.begin(), nums.end() - 1, 1LL * 0);
    ll last = nums[n-1];

    if (sum >= last) {
        cout << sum + last << endl;
    } else {
        cout << 2 * last << endl;
    }

    
}
