#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int dp[1000005][7];

int fn(int num, vector<int>& dices, int idx) {
    if (num == 0) return 1;
    if (idx >= 6) return 0;
    if (dp[num][idx] != -1) return dp[num][idx];
    int a = 0;
    if (num >= dices[idx])
        a = fn(num - dices[idx], dices, 0) % mod;
    int b = fn(num, dices, idx + 1) % mod;

    return dp[num][idx] = (a + b) % mod;
    
}

int main() {
    int num; cin >> num;
    vector<int> dices = {1,2,3,4,5,6};
    memset(dp, -1, sizeof(dp));
    int ans = fn(num, dices, 0);

    cout << ans << endl;
}