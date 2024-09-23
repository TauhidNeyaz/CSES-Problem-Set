#include <bits/stdc++.h>
using namespace std;

void fn(string &str) {

    int n = str.size();

    unordered_map<char, int> mpp;
    for (auto &c : str) {
        mpp[c]++;
    }

    int odd_count = 0;
    for (auto it : mpp) {
        if (it.second % 2) ++odd_count;
    }

    if (odd_count > 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    string ans1 = "", ans2 = "", odd = "";
    
    for (auto &it : mpp) {
        if (it.second % 2) {
            for (int k = 0; k < it.second; ++k) {
                odd.push_back(it.first);
            }
        } else {
            string s1;
            for (int k = 0; k < it.second / 2; ++k) {
                s1.push_back(it.first);
            } 
            ans1 += s1; ans2 += s1;
        }
    }

    reverse(ans2.begin(), ans2.end());

    cout << ans1 + odd + ans2 << endl;



}

int main() {
    string str; cin >> str;

    fn(str);

}