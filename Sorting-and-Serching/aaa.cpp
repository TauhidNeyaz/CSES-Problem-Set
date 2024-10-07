#include <bits/stdc++.h>
using namespace std;
  
int main() {
    
    multiset<int> mp;
    // mp.insert(1);
    mp.insert(6);

    // auto lb = mp.lower_bound(2);
    auto ub = mp.upper_bound(6);

    // lb = prev(lb);
    if (ub == mp.end()) cout << "end";
    else cout << *ub ;

    
}
