#include<bits/stdc++.h>
using namespace std;

void TowerOfHonai(int x, char source, char auxiliry, char destination) {
    if (x == 0) return;
    TowerOfHonai(x-1,source,destination,auxiliry);
    cout<<source<<" "<<destination<<endl;
    TowerOfHonai(x-1,auxiliry,source,destination);
}

int main() {
    int ring; cin>> ring;

    int ans = (int) pow(2, ring) - 1;

    cout << ans << endl;

    TowerOfHonai(ring, '1', '2', '3');
}