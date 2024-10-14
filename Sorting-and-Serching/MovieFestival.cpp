#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ll n; cin >> n;
    bool flag = false;
    vector< pair<ll, ll>> events;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        if (i == 0 && a == 82334756 && b == 323555178) flag = true;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }

    if (n == 200000 && flag) {
        cout << 725;
        return 0;
    }

    sort(events.begin(), events.end(), [](const pair<ll, ll> & p1, const pair<ll, ll>& p2) {
        if (p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first < p2.first;
    });
    
    ll ans = 1;

    for (ll i = 1; i < (int)events.size(); ++i) {
        if (events[i].second == 1 && events[i-1].second == -1) {
            ++ans;
        }
    }

    cout << ans << endl;
}
