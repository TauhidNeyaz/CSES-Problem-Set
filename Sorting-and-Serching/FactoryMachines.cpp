#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool fn(vector<ll>& v, ll k, ll times) {
    ll cnt = 0;
    for (auto &i : v) {
        cnt += 1LL * (times / i);
    }
    return cnt >= k;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> times(n);
    for (auto &i : times) cin >> i;

    sort(times.begin(), times.end());

    ll low = 1, high = 1LL * k * 1LL * times[0];
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (fn(times, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

/*
25 1000000000
1000000000 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
output => 41666667
*/