#include<bits/stdc++.h>
using namespace std;

vector< vector<int>> atk = { {1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1} };


long fn(int K) {

    long totalWays = ((long) K * K * (K * K - 1)) / 2;

    long attackingWays = 4 * (K - 1) * (K - 2);

    long ans = totalWays - attackingWays;

    return ans;

}

int main() {
    int n; cin>>n;

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            cout << 0 << endl;
        }
        else cout << fn(i) << endl;
    }

}