#include <bits/stdc++.h>
using namespace std;

long long fn(vector<int>& v, int val) {
    long long score = 0;
    for (auto &num : v) {
        score += abs(num - val);
    }
    return score;
}

int main() {
    int n; 
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    sort(v.begin(), v.end());
    
    long long high = v[n-1];
    long long low = v[0];
    long long ans = 1e18; 

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long curr_ans = fn(v, mid);

        if (fn(v, mid + 1) < curr_ans) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }

        ans = min(ans, curr_ans);
    }

    cout << ans << endl;
}
