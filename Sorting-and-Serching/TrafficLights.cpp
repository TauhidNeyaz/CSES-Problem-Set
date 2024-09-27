#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll size, n;
    cin >> size >> n;

    vector<ll> lights(n);
    for (auto &i : lights) cin >> i;

    // Multiset to store positions of the lights
    multiset<ll> positions;
    positions.insert(0);  // Initial boundary at position 0
    positions.insert(size);  // Initial boundary at position size

    // Multiset to store lengths of segments
    multiset<ll> segmentLengths;
    segmentLengths.insert(size);  // Initially, the whole segment [0, size] is a single segment

    for (const auto &val : lights) {
        // Find the position just after the new light (upper bound)
        auto upr = positions.upper_bound(val);
        auto lwr = prev(upr);  // The position just before the new light

        // Remove the old segment between *lwr and *upr
        segmentLengths.erase(segmentLengths.find(*upr - *lwr));

        // Insert the new segments created by the new light
        segmentLengths.insert(val - *lwr);  // New segment [*lwr, val]
        segmentLengths.insert(*upr - val);  // New segment [val, *upr]

        // Insert the new light position
        positions.insert(val);

        // The largest segment length will be the last element in the multiset
        cout << *segmentLengths.rbegin() << " ";
    }

    return 0;
}
