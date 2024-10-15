#include <bits/stdc++.h>
using namespace std;

/*
    dp[i][1] = last blocks are separate | || |
                                       _ _
    dp[i][0] = last blocks are fused |   |
    
    transition:
                 _  _    _  _    _  _    _  _     _ _
     _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
    | || | =>   | || |, | || |, | || |, | || |,  | | |

                 _ _    _ _    _ _ 
     _ _        |   |  |_|_|  |_ _|
    |   |  =>   |   |, |   |, |   |


*/



int main() {

    vector<vector<int>> dp(1e6 + 1, vector<int>(2, 0));
    int mod = 1e9 + 7;
    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 1; i <= 1e6; ++i) {
        dp[i][0] = (2LL * dp[i-1][0] + dp[i-1][1]) % mod;
        dp[i][1] = (4LL * dp[i-1][1] + dp[i-1][0]) % mod;
    }

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        cout << ((dp[n-1][0] + dp[n-1][1]) % mod) << endl;
    }
}
