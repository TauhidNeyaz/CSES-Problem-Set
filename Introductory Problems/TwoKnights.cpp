#include<bits/stdc++.h>
using namespace std;

vector< vector<int>> atk = { {1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1} };


int fn(int x) {

    int ans = 0;
    vector< vector<int>> mark(x, vector<int>(x, 0));

    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= x; ++j) {

            int attk_in_range = 0; 
            
            for (int k = 0; k < 8; ++k) {
                int a = i + atk[k][0];
                int b = j + atk[k][1];

                if (a >= 1 && a <= x && b >= 1 && b <= x) {
                    ++attk_in_range;
                }
                
            }

            ans += (x * x - attk_in_range - 1);

        }
    }

    return ans;

}

int main() {
    int n; cin>>n;

    for (int i = 1; i <= n; ++i) {
        set<pair<int, int>> marked;
        if (i == 1) {
            cout << 0 << endl;
        }
        else cout << fn(i) / 2 << endl;
    }

}