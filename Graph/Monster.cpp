#include <bits/stdc++.h>
using namespace std;
vector<char> ans;
int n, m;
bool flag = false;

bool is(vector<vector<char>>& grid, int i, int j) {
    return i > 0 && j > 0 && i < n && j < m && grid[i][j] == '.';
}

void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i == n-1 || j == m-1 || i == 0 || j == 0) {
        flag = true;
        return;
    }
    if (grid[i][j] == '0') return;
    grid[i][j] = '0';
    if( is(grid,i+1,j) && !flag ) {
        ans.push_back('D');
        dfs(grid, i+1, j);
    }
    if ( is(grid, i-1, j) && !flag) {
        ans.push_back('U');
        dfs(grid, i-1, j);
    }
    if ( is(grid, i, j+1) && !flag) {
        ans.push_back('R');
        dfs(grid, i, j+1);
    }
    if ( is(grid, i, j-1) && !flag) {
        ans.push_back('L');
        dfs(grid, i, j-1);
    }
}

int main() {
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>grid[i][j];
        }
    }
    int a = -1, b = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                a = i;
                b = j;
                break;
            }
        }
        if (a != -1) break;
    }
    if (a == 0 || b == 0 || a == n-1 || b == m-1) {
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0;
    }
    dfs(grid, a, b);
    if (!flag) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<ans.size()<<endl;
    for (auto it : ans) {
        cout<<it<<" ";
    }
}