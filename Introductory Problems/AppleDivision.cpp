#include <bits/stdc++.h>
using namespace std;

long long ans;

void fn(vector<int>& nums, int idx, long long x, long long y) {

    if (idx == nums.size()) {
        ans = min(1LL*ans, abs(x - y));
        return;
    }

    fn(nums, idx + 1, x + nums[idx], y);
    fn(nums, idx + 1, x, y + nums[idx]);

}

int main() {

    int n; cin >> n;
    vector<int> nums(n);
    for (auto &i : nums) cin >> i;

    ans = 1e9;
    long long x = 0, y = 0;

    fn(nums, 0, x, y);

    cout << ans << endl;

}