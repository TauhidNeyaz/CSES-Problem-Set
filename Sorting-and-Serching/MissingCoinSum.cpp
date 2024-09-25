#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    sort(v.begin(), v.end());

    ll ans = 1;
    for (auto &coin : v) {
        if (ans >= coin) {
            ans += coin;
        } else {
            break;
        }
    }

    cout << ans << endl; 
}