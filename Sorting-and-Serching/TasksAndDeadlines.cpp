#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;
    vector< pair<ll, ll>> nums(n);
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        nums[i] = {a, b};
    }

    ll curr_time = 0, ans = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {
        curr_time += nums[i].first;
        ans += (nums[i].second - curr_time);
    }

    cout << ans << endl;

}