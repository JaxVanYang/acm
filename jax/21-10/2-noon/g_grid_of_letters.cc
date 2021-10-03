#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = N * N;
const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
char grid[N][N];
int n, m;
int d[M];
bool vis[M];
vector<int> edges[M];

inline void add(int u, int v) {
    edges[u].push_back(v);
    ++d[v];
}

inline bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

inline int Hash(int x, int y) {
    return x * m + y;
}

int dfs(int u) {
    // cout << "u = " << u << endl;

    if (vis[u]) {
        return 0;
    }

    if (edges[u].empty()) {
        return 1;
    }

    int ret = 0;

    for (int v : edges[u]) {
        ret = max(ret, dfs(v));
    }

    vis[u] = true;

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
                    add(u, Hash(x, y));
                }
            }
        }
    }

    vector<pair<char, int>> us;

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int u = Hash(i, j);

            if (d[u] == 0) {
                us.push_back({grid[i][j], u});
            }
        }
    }

    sort(us.begin(), us.end());

    for (auto [ch, u] : us) {
        // cout << "ch = " << ch << " u = " << u << endl;

        ans = max(ans, dfs(u));

        if (ans == 26) {
            break;
        }
    }

    printf("%d\n", ans);
}