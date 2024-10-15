#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int dp[5005][5005];
int f(int i, int j) {
    if (i == s1.size()) return s2.size() - j;
    if (j == s2.size()) return s1.size() - i;
    if (s1[i] == s2[j]) return f(i+1, j+1);
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = min({1 + f(i+1, j+1), 1 + f(i+1, j), 1 + f(i, j+1)});
}
 
int main() {
	cin >> s1 >> s2;
    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << endl;
}