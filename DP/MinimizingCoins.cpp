#include<bits/stdc++.h>
using namespace std;
vector<int> coin;
vector<int> dp(1000005, -1);
int f(int x) {
    if (x == 0) return 0;
    if (dp[x] != -1) return dp[x];
    int res = INT_MAX;
    for (long long i = 0; i < coin.size(); i++) {
        if ((x - coin[i]) >= 0)
            res = min(res, f(x - coin[i]));
    }
    if (res == INT_MAX) return dp[x] = INT_MAX;
    return dp[x] = 1 + res;
}
 
int main() {
    long long n, target;
    cin>>n>>target;
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        coin.push_back(a);
    }
    int ans = f(target);
    if (ans == INT_MAX) cout<<"-1"<<endl;
    else cout<<ans<<endl;

}