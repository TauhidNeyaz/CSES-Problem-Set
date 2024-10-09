#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        nums[i] = {a, i+1};
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {
        int left = 0, right = n - 1;
        while (left < right) {
            
            if (i == left) {
                ++left; continue;
            }
            if (i == right) {
                --right; continue;
            }

            int sum = nums[i].first + nums[left].first + nums[right].first;
            
            if (sum == k) {
                cout << nums[i].second << " " << nums[left].second << " " << nums[right].second << endl;
                return 0;
            } else if (sum > k) {
                --right;
            } else {
                ++left;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}