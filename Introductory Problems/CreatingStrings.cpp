#include <bits/stdc++.h>
using namespace std;

set<string> ans;
void fn(string curr, string str) {
    
    if (str.size() == 0) {
        ans.insert(curr);
        return;
    }

    for (int i = 0; i < str.size(); ++i) {
        char ch = str[i];
        string left = str.substr(0, i);
        string right = str.substr(i+1);
        fn(curr+ch, left + right);
    }
}

int main() {
    string str; cin >> str;

    fn("", str);
    cout << ans.size() << endl;
    for (auto &s : ans) {
        cout << s << endl;
    }
}