#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;
char grid[N][N];
int ans[N][N];

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

inline bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> grid[i];
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ans[i][j] = -1;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (grid[i][j] == '1') {
        q.push({i, j});
        ans[i][j] = 0;
    }
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int r = x + dx[i], c = y + dy[i];
            if (valid(r, c) && ans[r][c] == -1) {
                ans[r][c] = ans[x][y] + 1;
                q.push({r, c});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << ans[i][j] << ' ';
        cout << endl;
    }
}