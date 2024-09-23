#include <bits/stdc++.h>
using namespace std;

int fn(string &str) {

    char prev = str[0];
    int maxCount = -1;
    int i = 0, j = 0;

    while (j < str.size()) {

        while (j < str.size() && str[j] == prev) {
            ++j;
        }

        maxCount = max(maxCount, j - i);
        i = j;
        prev = str[i];
    }

    return maxCount;
}

int main() {
    string str; cin >> str;
    cout << fn(str) << endl;
}