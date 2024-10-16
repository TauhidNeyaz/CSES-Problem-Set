#include <bits/stdc++.h>
using namespace std;

int fn(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        int seq = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) seq = max(seq, dp[j]);
        }
        dp[i] = seq + 1;
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << fn(nums);
}