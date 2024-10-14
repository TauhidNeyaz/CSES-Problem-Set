#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    ll n, k;
    cin >> n >> k;
    
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

    int ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> min_heap;

    for (auto timee : events) {

        while (!min_heap.empty() && timee[0] >= min_heap.top())
            min_heap.pop();

        if (min_heap.size() < k) {
            ++ans;
            min_heap.push(timee[1]);
        }
    }

    cout << ans << endl;

}

/*
10 2
62 83
38 87
99 100
37 74
17 86
40 44
70 81
65 97
11 85
92 95

ans = 5
*/