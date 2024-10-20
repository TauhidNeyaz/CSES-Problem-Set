#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Job {
public:
    ll s, f, p;
};

bool cmp(Job a, Job b) {
    return a.f < b.f;
}

int can_look_back(vector<Job>& nums, ll i) {
    ll hi = i - 1, lo = 0;

    while (lo <= hi) {
        ll m = lo + (hi - lo) / 2;

        if (nums[m].f < nums[i].s) {
            if (nums[m + 1].f < nums[i].s) {
                lo = m + 1;
            } else {
                return m;
            }
        } else {
            hi = m - 1;
        }
    }

    return -1;
}

int main() {
    int n; cin >> n;

    vector<Job> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i].s >> nums[i].f >> nums[i].p;
    }

    sort(nums.begin(), nums.end(), cmp);

    vector<ll> dp(n);
    dp[0] = nums[0].p;

    for (int i = 1; i < n; ++i) {

        ll incl = nums[i].p;
        ll excl = dp[i - 1];

        int idx = can_look_back(nums, i);

        if (idx != -1) {
            incl += dp[idx];
        }

        dp[i] = max(incl, excl);
    }

    cout << dp[n - 1];

}