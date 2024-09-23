#include <bits/stdc++.h>
using namespace std;

int ans;

bool isValid (vector< vector<char>>& grid, int i, int j) {

    for (int a = i-1; a >= 0; --a) {
        if (grid[a][j] == 'Q')
            return false;
    }

    for (int a = i-1, b = j-1; a >= 0 && b >= 0; --a, --b) {
        if (grid[a][b] == 'Q')
            return false;
    }

    for (int a = i-1, b = j+1; a >= 0 && b < 8; --a, ++b) {
        if (grid[a][b] == 'Q')
            return false;
    }

    return true;
}

void fn(vector< vector<char>>& grid, int i) {

    if (i == 8) {
        ++ans;
        return;
    }

    for (int k = 0; k < 8; ++k) {
        if (isValid(grid, i, k) && grid[i][k] == '.') {
            grid[i][k] = 'Q';
            fn(grid, i+1);
            grid[i][k] = '.';
        }
    }
}

int main() {

    vector< vector<char>> grid(8, vector<char>(8));
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> grid[i][j];
        }
    }

    ans = 0;

    fn(grid, 0);

    cout << ans << endl;

}