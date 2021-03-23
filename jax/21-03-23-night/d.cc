#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 55;
int g[maxn][maxn];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        memset(g, 0, sizeof g);
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) scanf("%d", &g[i][j]);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (g[i][j] == 0) continue;
                ++ans;
                for (int k = 0; k < 4; ++k) {
                    int r = i + dr[k], c = j + dc[k];
                    if (g[r][c] < g[i][j]) ans += g[i][j] - g[r][c];
                }
            }
        }
        printf("%d\n", ans);
    }
}