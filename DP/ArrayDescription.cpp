#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
int mod = 1e9+7;

int fn(vector<int>& v , int idx, int m) {
    if (idx == v.size()) 
        return 1;

    if (idx != 0 && abs(v[idx] - v[idx-1]) > 1) 
        return 0;

    if (dp[idx] != -1) 
        return dp[idx];

    int a = 0;
    if (v[idx] == 0) {
        for (int val = 1; val <= m; ++val) {
            v[idx] = val;
            a = (a + fn(v, idx + 1, m)) % mod;  
        }
        v[idx] = 0;  
    } else {
        a = fn(v, idx+1, m);  
    }

    return dp[idx] = a % mod;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    
    dp.resize(n+1, -1);  

    cout << fn(v, 0, m) << endl;  
}
