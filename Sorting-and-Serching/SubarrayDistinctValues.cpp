#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
    ll n, k; 
    cin >> n >> k;
    vector<ll> nums(n);

    for (auto &i : nums) cin >> i;
    unordered_map<ll, ll> dist;

    ll ans = 0;
    ll i = 0, j = 0, count = 0;

    while (j < n) {
        
        if (!dist.count(nums[j])) {
            ++count;
        }

        dist[nums[j]]++;

        while (count > k) {
            dist[nums[i]]--;
            if (dist[nums[i]] == 0) --count, dist.erase(nums[i]);
            ++i;
        }

        ans += 1LL *(j - i + 1);
        ++j;
        
    }

    cout << ans << endl;

}
