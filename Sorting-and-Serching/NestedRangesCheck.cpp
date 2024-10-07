#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;

    unordered_set<string> for_you, by_you;
    multiset<int> range;  
    vector<string> nums;

    while (n--) {
        int x, y;
        cin >> x >> y;

        auto lb = range.lower_bound(x);
        auto ub = range.upper_bound(y);
        if (range.size() >= 2) lb = prev(lb);

        string mpp = to_string(x) + "," + to_string(y);  
        nums.push_back(mpp);

        range.insert(x);
        range.insert(y);

        if (lb != range.begin() && ub != range.end()) {
            for_you.insert(mpp);
            string MPP = to_string(*lb) + "," + to_string(*ub);
            by_you.insert(MPP);

            cout << "--" << *lb << "  " << *ub << "--" << endl;
        }
    }

    for (auto &i : nums) {
        if (by_you.count(i)) cout << 1 << " ";
        else cout << 0 << " ";
    }
    cout << endl;

    for (auto &i : nums) {
        if (for_you.count(i)) cout << 1 << " ";
        else cout << 0 << " ";
    }

    return 0;
}


/*
4
1 6
2 4
4 8
3 6
*/