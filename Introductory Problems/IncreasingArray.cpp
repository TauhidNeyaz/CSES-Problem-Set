#include <bits/stdc++.h>
using namespace std;

long long fn(vector<long long>& v) {
    long long ans = 0;

    for (int i = 1; i < v.size(); ++i) {
        if (v[i] < v[i-1]) {
            ans += (v[i-1] - v[i]);
            v[i] = v[i-1];
        }
    }
    return ans;
}

int main() {
    long long n; cin>>n;
    vector<long long> v(n);
    for (long long &i : v) cin>>i;

    cout << fn(v) << endl;
}