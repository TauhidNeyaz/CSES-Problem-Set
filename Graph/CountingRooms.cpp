#include <bits/stdc++.h>
using namespace std;

vector< vector<int>> dir = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(vector<vector<char>>& grid, int i, int j) {

    int n = grid.size();
    int m = grid[0].size();

    queue< pair<int, int>> que;
    que.push({i, j});
    grid[i][j] = '#';

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (int d = 0; d < 4; ++d) {
            int new_x = dir[d][0] + x;
            int new_y = dir[d][1] + y;

            if (new_x >= n || new_x < 0 || new_y >= m || new_y < 0 || grid[new_x][new_y] != '.')
                continue;
            
            grid[new_x][new_y] = '#';
            que.push({new_x, new_y});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector< vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                ++ans;
                bfs(grid, i, j);
            }
        }
    }

    cout << ans << endl;

}