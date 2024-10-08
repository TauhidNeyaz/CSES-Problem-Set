#include <bits/stdc++.h>
using namespace std;

#define pp pair<int, int>

int main() {
    int n; cin >> n;
    vector<vector<int>> times(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        times[i] = {x, y, i};
    }
    vector<int> rooms_allocated(n);
    int curr_room_number = 1;

    sort(times.begin(), times.end());
    priority_queue<pp, vector<pp>, greater<pp>> min_heap;
    min_heap.push({times[0][1], curr_room_number});
    rooms_allocated[times[0][2]] = 1;
    
    for (int i = 1; i < n; ++i) {
        int idx = times[i][2];
        pp p = min_heap.top();
        if (p.first < times[i][0]) {
            min_heap.pop();
            rooms_allocated[idx] = p.second;
            min_heap.push({times[i][1], p.second});
        } else {
            rooms_allocated[idx] = ++curr_room_number;
            min_heap.push({times[i][1], curr_room_number});
        }

    }
    cout << curr_room_number << endl;
    for (auto &i : rooms_allocated) {
        cout << i << " ";
    }
}