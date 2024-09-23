#include <bits/stdc++.h>
using namespace std;

long long modExpo(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;  
    
    while (exp > 0) {
        
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        
        base = (base * base) % mod;
        
        exp /= 2;
    }
    
    return result;
}

int main() {
    int n;
    
    cin >> n;
    long long mod = 1e9 + 7;
    long long ans = 2;

    ans = modExpo(ans, 1LL*n, mod) % mod;

    cout << ans << endl;
    
    return 0;
}
