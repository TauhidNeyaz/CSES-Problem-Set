#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    sort(v.begin(), v.end());
    long long ans = 0;

    int i = 0, j = n-1;

    while (i <= j) {

        if (v[i] + v[j] <= k) {
            ++i; --j;
        } else {
             --j;
        }
        ++ans;
    }

    cout << ans << endl;
}