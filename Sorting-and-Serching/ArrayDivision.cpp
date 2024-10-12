#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool canDivide(vector<ll>& nums, ll k, ll sub_sum) {

    ll sum = 0, K = 1;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (sum > sub_sum) {
            sum = nums[i];
            ++K;
        }
    }

    return K <= k;

}

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> nums(n);
    for (auto &i : nums) cin >> i;

    ll high = accumulate(nums.begin(), nums.end(), 0LL); 
    ll low = *max_element(nums.begin(), nums.end());
    ll ans = 0;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (canDivide(nums, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}
