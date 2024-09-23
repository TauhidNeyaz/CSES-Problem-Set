#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    vector< pair<int, int>> pairs;

    for (int i = 0; i < n; ++i) {
        pairs.push_back({v[i], i});
    }

    sort(pairs.begin(), pairs.end());
    int x = -1, y = -1;

    int i = 0, j = n-1;
    while (i < j) {
        if (pairs[i].first + pairs[j].first == k) {
            x = pairs[i].second + 1;
            y = pairs[j].second + 1;
            break;
        } else if (pairs[i].first + pairs[j].first > k) {
            --j;
        } else {
            ++i;
        }
    }

    if (x != -1 && y != -1) 
        cout << x << " " << y << endl;
    else 
        cout << "IMPOSSIBLE" << endl;

}