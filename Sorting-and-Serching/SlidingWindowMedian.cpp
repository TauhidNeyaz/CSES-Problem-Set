#include <bits/stdc++.h>
using namespace std;

vector<int> medianSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    unordered_map<int, int> lazy_remove;

    for (int i = 0; i < k; ++i) {
        max_heap.push(nums[i]);
    }
    for (int i = 0; i < (k / 2); ++i) {
        min_heap.push(max_heap.top());
        max_heap.pop();
    }

    for (int i = k; i <= nums.size(); ++i) {
        if (k % 2) {
            ans.push_back(max_heap.top());
        } else {
            ans.push_back(min(max_heap.top(), min_heap.top()));
        }

        if (i == nums.size()) break;

        int to_add = nums[i], to_remove = nums[i - k];
        int balance = 0;

        if (to_remove <= max_heap.top()) {
            --balance;
            if (to_remove == max_heap.top()) {
                max_heap.pop();
            } else {
                lazy_remove[to_remove]++;
            }
        } else {
            ++balance;
            if (to_remove == min_heap.top()) {
                min_heap.pop();
            } else {
                lazy_remove[to_remove]++;
            }
        }

        if (!max_heap.empty() && to_add <= max_heap.top()) {
            ++balance;
            max_heap.push(to_add);
        } else {
            --balance;
            min_heap.push(to_add);
        }

        if (balance < 0) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else if (balance > 0) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        while (!min_heap.empty() && lazy_remove[min_heap.top()]) {
            lazy_remove[min_heap.top()]--;
            min_heap.pop();
        }
        while (!max_heap.empty() && lazy_remove[max_heap.top()]) {
            lazy_remove[max_heap.top()]--;
            max_heap.pop();
        }
    }

    return ans;
}
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (auto &i : nums) cin >> i;

    vector<int> ans = medianSlidingWindow(nums, k);

    for (auto &i : ans) cout << i << " ";

}