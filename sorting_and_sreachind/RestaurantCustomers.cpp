#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> event;
    for (int i = 0; i < n; ++i) {
        int a, b; 
        cin >> a >> b;
        event.push_back({a, 1});
        event.push_back({b, -1});
    }

    sort(event.begin(), event.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first)
            return a.second < b.second;  
        return a.first < b.first;
    });

    int count = 0, max_count = -1;
    for (auto & pp : event) {
        count += pp.second;
        max_count = max(max_count, count);
    }

    cout << max_count << endl;
}