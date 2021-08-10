#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int inf = 0x3f3f3f3f;
char grid[N][N];
int dis[N][N];
int n, m;
const int dx[] = {-1, 1, -1, 1};
const int dy[] = {-1, 1, 1, -1};
const int sx[] = {-1, 0, -1, 0};
const int sy[] = {-1, 0, 0, -1};
const char ch[] = {'\\', '\\', '/', '/'};

inline bool valid(int x, int y) {
    return 0 <= x && x <= n && 0 <= y && y <= m;
}
inline bool valid(pair<int, int> &p) {
    return valid(p.first, p.second);
}

void solve() {
    deque<pair<int, int>> q;
    q.push_back({0, 0});
    while (q.size()) {
        auto [x, y] = q.front();
        if (x == n && y == m) break;
        q.pop_front();
        for (int i = 0; i < 4; ++i) {
            auto nex = make_pair(x + dx[i], y + dy[i]);
            if (valid(nex)) {
                int xs = x + sx[i], ys = y + sy[i];
                if (grid[xs][ys] == ch[i] && dis[x][y] < dis[nex.first][nex.second]) {
                    dis[nex.first][nex.second] = dis[x][y];
                    q.push_front(nex);
                } else if (grid[xs][ys] != ch[i] && dis[x][y] + 1 < dis[nex.first][nex.second]) {
                    dis[nex.first][nex.second] = dis[x][y] + 1;
                    q.push_back(nex);
                }
            }
        }
    }
    if (dis[n][m] != inf)
        cout << dis[n][m] << endl;
    else
        cout << "NO SOLUTION" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> grid[i];
        memset(dis, 0x3f, sizeof dis);
        dis[0][0] = 0;
        solve();
    }
}