#include <bits/stdc++.h>
using namespace std;

int n = 7;
int ans;

vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}}; // L R D U

void fn(string &path, int idx, int i, int j, vector<vector<int>> &mark) {
    if (i == n - 1 && j == 0) {
        if (idx == path.size()) {
            ++ans;
        }
        return;
    }

    if (idx >= path.size()) {
        return;
    }

    if (path[idx] == '?') {
        for (int d = 0; d < 4; ++d) {
            int new_i = i + dir[d][0];
            int new_j = j + dir[d][1];

            if (new_i >= n || new_i < 0 || new_j >= n || new_j < 0 || mark[new_i][new_j]) {
                continue;
            }

            mark[new_i][new_j] = 1;
            fn(path, idx + 1, new_i, new_j, mark);
            mark[new_i][new_j] = 0; 
        }
    } else {
        if (path[idx] == 'U' && i > 0 && !mark[i - 1][j]) {
            mark[i - 1][j] = 1;
            fn(path, idx + 1, i - 1, j, mark);
            mark[i - 1][j] = 0; 
        }
        else if (path[idx] == 'D' && i < n - 1 && !mark[i + 1][j]) {
            mark[i + 1][j] = 1;
            fn(path, idx + 1, i + 1, j, mark);
            mark[i + 1][j] = 0; 
        }
        else if (path[idx] == 'L' && j > 0 && !mark[i][j - 1]) {
            mark[i][j - 1] = 1;
            fn(path, idx + 1, i, j - 1, mark);
            mark[i][j - 1] = 0; 
        }
        else if (path[idx] == 'R' && j < n - 1 && !mark[i][j + 1]) {
            mark[i][j + 1] = 1;
            fn(path, idx + 1, i, j + 1, mark);
            mark[i][j + 1] = 0; 
        }
    }
}

int main() {
    string path;
    cin >> path;
    ans = 0;
    vector<vector<int>> mark(n, vector<int>(n, 0));
    mark[0][0] = 1;
    fn(path, 0, 0, 0, mark);

    cout << ans << endl;
}
