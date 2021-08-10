#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 808;
char grid[N][N];
int n, m;
int vis[N][N];
int xb, yb, xg, yg, x1, y1, x2, y2;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

inline bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && grid[x][y] != 'X';
}
bool valid(int x, int y, int t) {
    int dis1 = abs(x - x1) + abs(y - y1);
    int dis2 = abs(x - x2) + abs(y - y2);
    return valid(x, y) && dis1 > 2 * t && dis2 > 2 * t;    
}
bool valid(pair<int, int> &p, int t) {
    return valid(p.first, p.second, t);
}

void parse_input() {
    x1 = -1;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (grid[i][j] == 'M') {
        xb = i, yb = j;
    } else if (grid[i][j] == 'G') {
        xg = i, yg = j;
    } else if (grid[i][j] == 'Z') {
        if (x1 == -1) x1 = i, y1 = j;
        else x2 = i, y2 = j;
    }
}

int solve() {
    queue<pair<int, int>> q1, q2;
    vis[xb][yb] = 1, vis[xg][yg] = 2;
    q1.push({xb, yb}), q2.push({xg, yg});
    int t = 0;
    while (q1.size() && q2.size()) {
        // cout << "q1.size = " << q1.size() << " q2.size = " << q2.size() << endl;
        ++t;
        for (int _ = 0; _ < 3 && q1.size(); ++_) {
            int len = q1.size();
            while (len--) {
                auto [x, y] = q1.front();
                q1.pop();
                if (!valid(x, y, t)) continue;
                for (int i = 0; i < 4; ++i) {
                    auto nex = make_pair(x + dx[i], y + dy[i]);
                    if (valid(nex, t) && (vis[nex.first][nex.second] & 1) == 0) {
                        // cout << "nex.x = " << nex.first << " nex.y = " << nex.second << endl;
                        if (vis[nex.first][nex.second] == 2) return t;
                        vis[nex.first][nex.second] |= 1;
                        q1.push(nex);
                    }
                }
            }
        }
        int len = q2.size();
        while (len--) {
            auto [x, y] = q2.front();
            // cout << "x = " << x << " y = " << y << endl;
            q2.pop();
            if (!valid(x, y, t)) continue;
            for (int i = 0; i < 4; ++i) {
                auto nex = make_pair(x + dx[i], y + dy[i]);
                if (valid(nex, t) && (vis[nex.first][nex.second] & 2) == 0) {
                    if (vis[nex.first][nex.second] == 1) return t;
                    vis[nex.first][nex.second] |= 2;
                    q2.push(nex);
                }
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> grid[i];
        memset(vis, 0, sizeof vis);
        parse_input();
        cout << solve() << endl;;
    }
}