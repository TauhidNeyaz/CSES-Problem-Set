#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;
    vector<ll> nums(n);
    for (auto &i : nums) cin >> i;

    unordered_map<ll, ll> mpp;
    mpp[0]++;

    ll ans = 0, curr_sum = 0;
    for (auto &num : nums) {
        curr_sum += num;
        int rem = ((curr_sum % n + n) % n );
        if (mpp.count(rem)) {
            ans += mpp[rem];
        }
        mpp[rem]++;
    }

    cout << ans << endl;
}