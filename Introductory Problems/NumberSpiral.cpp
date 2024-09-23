#include <bits/stdc++.h>
using namespace std;

int main() {

    int tt; cin>>tt;
    while (tt--) {
        long long x, y;
        cin >> x >> y;

        long long ans; 

        if (x >= y) {
            if (x % 2 == 0) {
                ans = 1LL*x * 1LL*x - 1LL*(y - 1);
            } else {
                ans = 1LL*(x-1) * 1LL*(x-1) + 1 + 1LL*(y - 1);
            }
        } else {
            if (y % 2 == 0) {
                ans = 1LL*(y-1) * 1LL*(y-1) + 1 + 1LL*(x - 1);
            } else {
                ans = 1LL*y * 1LL*y - 1LL*(x - 1);
            }
        }

        cout << ans << endl;
    }

}