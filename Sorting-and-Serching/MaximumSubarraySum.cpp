#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    long long ans = INT_MIN;
    long long sum = 0;

    for (auto &num : v) {
        sum += num;
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }

    cout << ans << endl;
}