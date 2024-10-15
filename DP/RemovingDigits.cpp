#include <bits/stdc++.h>
using namespace std;

int mx(int x) {
    int mx_d = -1;
    while (x > 0) {
        mx_d = max(x % 10, mx_d);
        x /= 10;
    }
    return mx_d;
}

int fn(int num) {
    if (num == 0) return 0;

    int mx_digit = mx(num);
    return 1 + fn(num - mx_digit);
}

int main() {
    int num; cin >> num;

    cout << fn(num) << endl;
}