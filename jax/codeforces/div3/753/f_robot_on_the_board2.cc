#include <iostream>
#include <cstring>
#include <stack>

const int N = 2e3 + 10;
char grid[N][N];
int ans[N][N];
int mark[N][N];
int dr[128], dc[128];
int n, m;

inline bool valid(int r, int c) {
    return 1 <= r && r <= n && 1 <= c && c <= m;
}

void init() {
    dc['L'] = -1;
    dc['R'] = 1;
    dr['U'] = -1;
    dr['D'] = 1;
}

void reset(const int n, const int m) {
    for (int i = 1; i <= n; ++i) {
        memset(ans[i] + 1, 0, sizeof(int) * m);
        memset(mark[i] + 1, 0, sizeof(int) * m);
    }
}

void dfs(int r, int c, int p) {
    if (ans[r][c]) return;

    std::stack<std::pair<int, int>> stk;
    int x = r, y = c;
    while (valid(x, y)) {

        std::pair<int, int> tmp(x, y);
        if (mark[x][y] == p) {
            int cnt = 1;
            while (stk.top() != tmp) {
                ++cnt;
                stk.pop();
            }
            stk.pop();

            int i = x, j = y;
            do {
                ans[i][j] = cnt;
                int di = dr[grid[i][j]], dj = dc[grid[i][j]];
                i += di, j += dj;
            } while (i != x || j != y);
            break;
        }

        if (ans[x][y]) break;

        mark[x][y] = p;
        stk.push(tmp);
        int dx = dr[grid[x][y]], dy = dc[grid[x][y]];
        x += dx, y += dy;
    }

    if (!valid(x, y)) {
        ans[x][y] = 0;
    }
    while (stk.size()) {
        auto [i, j] = stk.top();
        stk.pop();
        ans[i][j] = ans[x][y] + 1;
        x = i, y = j;
    }
}

void solve() {
    scanf("%d%d", &n, &m);
    reset(n, m);

    for (int i = 1; i <= n; ++i) {
        scanf("%s", grid[i] + 1);
    }

    int row = 0, col = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dfs(i, j, i * m + j);

            if (ans[i][j] > ans[row][col]) {
                row = i, col = j;
            }
        }
    }

    printf("%d %d %d\n", row, col, ans[row][col]);
}

int main() {
    init();
    
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}