#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    ll n;
    cin >> n;
    
    vector< vector<ll>> events;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        events.push_back({a, b});
    }

    sort(events.begin(), events.end(), [](vector<ll> & p1, vector<ll> p2) {
        if (p1[1] == p2[1])
            return p1[0] < p2[0];
        return p1[1] < p2[1];
    });

    int ans = 1;
    int last = events[0][1];
    
    for (int i = 1; i < n; ++i) {
        if (last <= events[i][0]) {
            ++ans;
            last = events[i][1];
        }
    }
    cout << ans << endl;

}
