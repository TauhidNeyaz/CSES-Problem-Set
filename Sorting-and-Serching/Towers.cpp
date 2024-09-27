#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> cubes(n);
    for (auto &i : cubes) cin >> i;

    int ans = 0;
    multiset<int> base;

    for (auto &cube : cubes) {

        auto upr = base.upper_bound(cube);
        if (upr != base.end()) {
            base.erase(upr);
            base.insert(cube);
        } else {
            ++ans;
            base.insert(cube);
        }
    }

    cout << ans << endl;

}