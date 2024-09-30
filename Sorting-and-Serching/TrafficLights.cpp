#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll size, n;
    cin >> size >> n;

    vector<ll> lights(n);
    for (auto &i : lights) cin >> i;

    multiset<ll> positions;
    positions.insert(0);  
    positions.insert(size); 

    multiset<ll> segmentLengths;
    segmentLengths.insert(size);  

    for (const auto &val : lights) {
        
        auto upr = positions.upper_bound(val);
        auto lwr = prev(upr);  
        segmentLengths.erase(segmentLengths.find(*upr - *lwr));

        segmentLengths.insert(val - *lwr);  
        segmentLengths.insert(*upr - val);  

        positions.insert(val);

        cout << *segmentLengths.rbegin() << " ";
    }

    return 0;
}
