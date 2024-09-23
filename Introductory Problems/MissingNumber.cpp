#include <bits/stdc++.h>
using namespace std;

#define ll int

ll fn(vector<ll>& v, ll n) {

    ll total = (1LL*n * 1LL*(n + 1)) / 2;
    ll curr = accumulate(v.begin(), v.end(), 0);

    return total - curr;
}

int main() {
    ll n; cin >> n;
    vector<ll> v(n-1);
    for (auto &i : v) cin>>i;
    cout << fn(v, n) << endl;
}