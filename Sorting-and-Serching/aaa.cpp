#include <bits/stdc++.h>
using namespace std;

bool fn(int n, unordered_set<int>& st) {
    if (n == 1)  
        return true;
    if (st.count(n))  
        return false;

    int num = 0;
    st.insert(n);  
    while (n > 0) {
        int rem = n % 10;
        num += (rem * rem);  
        n /= 10;
    }
    
    cout << num << " "; 
    return fn(num, st);  
}

int main() {
    int n;
    cin >> n;
    
    unordered_set<int> st;
    if (fn(n, st)) {
        cout << "YES" << endl;  
    } else {
        cout << "NO" << endl;   
    }

    
}
