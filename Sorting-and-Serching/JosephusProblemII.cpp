#include <bits/stdc++.h>
using namespace std;

void fn(int n, int k, set<int>& st) {
    set<int> :: iterator it;
    int skip = 0;
    while (!st.empty()) {
        skip = (skip + k) % st.size();
        it = st.begin();
        advance(it, skip);
        cout << *it << " ";
        st.erase(*it);
    }
}

int main() {
    int n, k; 
    cin >> n >> k;
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        st.insert(i);
    }

    fn(n, k, st);
}