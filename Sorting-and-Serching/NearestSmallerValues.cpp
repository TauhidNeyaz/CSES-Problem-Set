#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    
    for (auto &i : nums) cin >> i;

    stack<int> stk;
    vector<int> ans(n);
    ans[0] = 0;
    stk.push(0);

    for (int i = 1; i < n; ++i) {

        while (!stk.empty() && nums[i] <= nums[stk.top()]) {
            stk.pop();
        }

        ans[i] = !stk.empty() ? stk.top() + 1 : 0;
        stk.push(i);
    }

    for (auto &i : ans) cout << i << " ";
}