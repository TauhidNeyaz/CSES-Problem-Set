#include <bits/stdc++.h>

#define loop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(r); i >= (int)(l); --i)

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pp;
typedef vector<pp> vpp;

vector<vi> vis;
vector<vi> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;
queue<pp> Q;
vector<vi> min_time;
vector<vector<char>> grid;
bool found = false;
pp ans_found;
string ans_path;
vector<vpp> from_cell;



void bfs_monster() {
    int timee = 1;
    while (!Q.empty()) {
        int size = Q.size();
        while (size--) {
            pp curr = Q.front();
            Q.pop();

            int d;
            loop(d, 0, 3) {
                int A = curr.fi + dir[d][0];
                int B = curr.se + dir[d][1];

                if (A < n && B < m && A >= 0 && B >= 0 && grid[A][B] != '#' && min_time[A][B] == 1e9) {
                    min_time[A][B] = timee;
                    Q.push({A, B});
                }
            }
        }
        ++timee;
    }
}

void bfs_A(int a, int b) {
    Q.push({a, b});
    vis[a][b] = 1;

    int timee = 1;

    while (!Q.empty() && !found) {
        int size = Q.size();
        while (size--) {
            pp curr = Q.front();
            Q.pop();

            if (curr.fi == 0 || curr.fi == n-1 || curr.se == 0 || curr.se == m-1) {
                found = true;
                ans_found = curr;
                break;
            }

            int d;
            loop(d, 0, 3) {
                int A = curr.fi + dir[d][0];
                int B = curr.se + dir[d][1];

                if (A < n && B < m && A >= 0 && B >= 0 && grid[A][B] == '.' && vis[A][B] == 0) {
                    if (timee < min_time[A][B]) {
                        from_cell[A][B] = curr;
                        Q.push({A, B});
                        vis[A][B] = 1; // Mark as visited
                    }
                }
            }
        }
        ++timee;
    }
}

void make_path(pp node) {  
	pp origin = from_cell[node.first][node.second];
	if (origin == pp(-1, -1)) return;
	if (origin.first == node.first + 1) ans_path.push_back('U');
	if (origin.first == node.first - 1) ans_path.push_back('D');
	if (origin.second == node.second + 1) ans_path.push_back('L');
	if (origin.second == node.second - 1) ans_path.push_back('R');
	make_path(origin);
}

void Tauhid() {
    // Reset all global variables
    grid.clear();
    vis.clear();
    min_time.clear();
    from_cell.clear();
    found = false;
    while (!Q.empty()) Q.pop();

    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    vis.resize(n, vi(m, 0));
    min_time.resize(n, vi(m, 1e9));
    from_cell.resize(n, vpp(m, {-1,-1}));

    int i, j, a, b;
    loop(i, 0, n-1) {
        loop(j, 0, m-1) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                a = i, b = j;
            }
            if (grid[i][j] == 'M') {
                Q.push({i, j});
                min_time[i][j] = 0;
            }
        }
    }

    bfs_monster();
    bfs_A(a, b);

    if (found) {
        cout << "YES" << endl;
        make_path(ans_found);
        reverse(ans_path.begin(), ans_path.end());
        cout << ans_path.size() << endl;
        cout << ans_path;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Tauhid();
    return 0;
}
