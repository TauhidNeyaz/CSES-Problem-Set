#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> nums(n);
    for (auto &i : nums) cin >> i;

    unordered_set<ll> seen_before;
    seen_before.insert(0);
    ll ans = 0, curr_sum = 0;

    for (auto &i : nums) {
        curr_sum += i;

        if (seen_before.count(curr_sum - k)) 
            ++ans;
        
        seen_before.insert(curr_sum);
    }

    cout << ans << endl;
}

/*
5 7
2 4 1 2 7
0 2 6 7 9 16
*/