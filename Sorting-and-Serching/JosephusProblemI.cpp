#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    set<int> nums;
    for (int i = 1; i <= n; ++i) {
        nums.insert(i);
    }
    int curr_num = 1;

    while (!nums.empty()) {
        auto ub = nums.upper_bound(curr_num);
        if (ub == nums.end()) {
            cout << *nums.begin() << " ";
            nums.erase(*nums.begin());
            curr_num = *nums.begin();
        } else {
            cout << *ub << " ";
            if (ub == --nums.end()) {
                nums.erase(*ub);
                curr_num = *nums.begin();
            } else {
                nums.erase(*ub);
                curr_num = *nums.upper_bound(curr_num);
            }
        }
    }
}