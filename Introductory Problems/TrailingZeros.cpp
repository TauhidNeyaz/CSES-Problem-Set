#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;

    long long div = 5;
    long long ans = 0;

    while (div <= n) {
        ans += (n / div);
        div *= 5;
    }

    cout << ans << endl;
}