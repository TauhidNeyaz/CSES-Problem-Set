#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string direction = "DRUL";

vector<vector<char>> steps(1000, vector<char>(1000, '#'));
vector<vector<bool>> visited(1000, vector<bool>(1000, false));
stack<char> stk;
int A, B;

void findPath(int a, int b) {
    char chr = steps[a][b];
    if (chr == 'X') {
        return;
    }
    stk.push(chr);

    if (chr == 'U') {
        findPath(a + 1, b);
    } else if (chr == 'D') {
        findPath(a - 1, b);
    } else if (chr == 'L') {
        findPath(a, b + 1);
    } else if (chr == 'R') {
        findPath(a, b - 1);
    }
}

void reset(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = false;
            steps[i][j] = '#';
        }
    }
    while (!stk.empty()) stk.pop();
}

string bfs(vector<vector<char>>& grid, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> que;
    que.push({i, j});

    visited[i][j] = 1;
    steps[i][j] = 'X';
    bool flag = false;

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        if (grid[x][y] == 'B') {
            flag = true;
            break;
        }

        for (int d = 0; d < 4; ++d) {
            int X = x + dir[d][0];
            int Y = y + dir[d][1];

            if (X >= n || X < 0 || Y >= m || Y < 0 || visited[X][Y] == 1 || grid[X][Y] == '#')
                continue;

            visited[X][Y] = 1;
            steps[X][Y] = direction[d];
            que.push({X, Y});
        }
    }

    if (flag) {
        findPath(A, B);
        string ans;
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
    return "";
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    int x = -1, y = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                x = i;
                y = j;
            }
            if (grid[i][j] == 'B') {
                A = i, B = j;
            }
        }
    }

    if (x == -1 || y == -1) {
        cout << "NO" << endl;
        return 0;
    }

    reset(n, m);
    string ans = bfs(grid, x, y);

    if (ans.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    }

    return 0;
}
