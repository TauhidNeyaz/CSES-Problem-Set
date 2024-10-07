#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;

    vector<int> for_you, by_you;
    vector<vector<int>> nums;
    
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        nums.push_back({a, b, i});
    }

    sort(nums.begin(), nums.end(), [] (vector<int>& v1, vector<int>& v2) {
        if (v1[0] == v2[0]) return v1[1] > v2[1];
        return v1[0] < v2[0];
    });

    vector<int> contain_range(n, 0), contribute_range(n, 0);

    int min_end = 2e9;
    for (int i = n-1; i >= 0; --i) {
        if (nums[i][1] >= min_end) {
            contain_range[nums[i][2]] = 1;
        }
        min_end = min(min_end, nums[i][1]);
    }

    int max_end = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i][1] <= max_end) {
            contribute_range[nums[i][2]] = 1;
        }
        max_end = max(max_end, nums[i][1]);
    }

    for (auto &i : contain_range) cout << i << " ";
    cout << endl;
    for (auto &i : contribute_range) cout << i << " ";


    return 0;
}


/*
4
1 6
2 4
4 8
3 6

1,6,0  2,4,1  3,6,3  4,8,2

*/