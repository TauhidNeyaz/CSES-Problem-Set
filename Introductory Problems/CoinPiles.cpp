#include <iostream>
using namespace std;

bool canEmptyPiles(int a, int b) {
    if ((a + b) % 3 != 0) {
        return false;
    }
    
    if (a > 2 * b || b > 2 * a) {
        return false;
    }
    
    return true;
}

int main() {
    
    int tt; cin>> tt;

    while (tt--) {
        int a, b;
        cin >> a >> b;
        
        if (canEmptyPiles(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
