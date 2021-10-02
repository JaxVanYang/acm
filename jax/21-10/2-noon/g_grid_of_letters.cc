#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e3 + 10;
const int LMT = N * N;

char grid[N][N];
int n, m;
vector<int> edges[LMT];
int d[LMT];
bool vis[LMT];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

inline bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

inline void add(int u, int v) {
    edges[u].push_back(v);
}

inline int Hash(int x, int y) {
    return x * m + y;
}

int dfs(int cur) {
    if (vis[cur]) {
        return 0;
    }

    // cout << "cur = " << cur << endl;
    if (edges[cur].empty()) {
        return 1;
    }

    int ret = 0;

    for (int v : edges[cur]) {
        if (!vis[v]) {
            ret = max(ret, dfs(v));
        }
    }

    vis[cur] = true;

    return ret + 1;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int u = Hash(i, j);
            for (int k = 0; k < 8; ++k) {
                int x = i + dx[k], y = j + dy[k];

                if (valid(x, y) && grid[x][y] == grid[i][j] + 1) {
                    int v = Hash(x, y);

                    // cout << grid[i][j] << " -> " << grid[x][y] << endl;
                    // cout << u << " -> " << v << endl;
                    add(u, v);
                    ++d[v];
                }
            }
        }
    }

    // vector<int> begins;
    vector<pair<char, int>> begins;

    for (int i = 0; i < n * m; ++i) {
        if (d[i] == 0) {
            begins.push_back({grid[i / m][i % m], i});
        }
    }

    sort(begins.begin(), begins.end());

    int ans = 0;

    for (auto [ch, begin] : begins) {
        // cout << "begin = " << begin << endl;
        ans = max(ans, dfs(begin));

        if (ans == 26) {
            break;
        }
    }

    printf("%d\n", ans);
}