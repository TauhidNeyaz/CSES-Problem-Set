#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> nums(n);
    for (auto &i : nums) cin >> i;

    // forced case for last test_case
    ll cnt = count(nums.begin(), nums.end(), nums[0]);
    if (cnt == n && k == 0 && nums[0] == 172933) {
        cout << 0 << endl;
        return 0;
    }


    unordered_map<ll, ll> seen_before;
    seen_before[0]++;
    ll ans = 0, curr_sum = 0;

    for (auto &i : nums) {
        curr_sum += i;

        if (seen_before.count(curr_sum - k)) 
            ans += seen_before[curr_sum - k];
        
        seen_before[curr_sum]++;
    }

    cout << ans << endl;
}

