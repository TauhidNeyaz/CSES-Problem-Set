#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(ll N, vector<ll> & songs)
{
    ll start = 0, ans = 0;

    map<ll, ll> mp;

    for (ll end = 0; end < N; end++) {
      
        if (mp.find(songs[end]) == mp.end())
            mp.insert({ songs[end], end });
        else {
         
            if (mp[songs[end]] >= start)
                start = mp[songs[end]] + 1;
        
            mp[songs[end]] = end;
        }
        
        ans = max(ans, end - start + 1);
    }
    return ans;
}

int main() {
    ll n; cin >> n;
    vector<ll> songs(n);
    for (auto &i : songs) cin >> i;

    cout << solve(n, songs) << endl;
}