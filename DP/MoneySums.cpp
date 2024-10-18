#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> dp;
    set<int> present;
    dp.push_back(nums[0]);
    present.insert(nums[0]);

    for (int i = 1; i < n; ++i) {
        vector<int> temp; 

        for (int j = 0; j < dp.size(); ++j) {
            int newSum = dp[j] + nums[i];
            if (!present.count(newSum)) {
                temp.push_back(newSum);
                present.insert(newSum);
            }
        }

        if (!present.count(nums[i])) {
            temp.push_back(nums[i]);
            present.insert(nums[i]);
        }

        dp.insert(dp.end(), temp.begin(), temp.end());
    }

    sort(dp.begin(), dp.end());
    cout << dp.size() << endl;
    for (int i = 0; i < dp.size(); ++i) {
        cout << dp[i] << " ";
    }
}
