#include <bits/stdc++.h>
using namespace std; 

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> size_want(n), size_present(m);

    for (auto &i : size_want) cin >> i;
    for (auto &i : size_present) cin >> i;

    sort(size_want.begin(), size_want.end());
    sort(size_present.begin(), size_present.end());

    int i = 0, j = 0;
    int ans = 0;

    while (i < n && j < m) {

        int low = size_want[i] - k;
        int high = size_want[i] + k;
        if (size_present[j] >= low && size_present[j] <= high) {
            ++ans;
            ++i; ++j;
        } else if (size_present[j] < low) {
            ++j;
        } else {
            ++i;
        }

    }

    cout << ans << endl;
    
}