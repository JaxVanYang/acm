#include <iostream>
using namespace std;
const int maxn = 5005;
int grid[maxn][maxn];

int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    // r = min(5001, r);
    int xx, yy; // 用于记录边界
    xx = yy = r;    // xx, yy 至少比 r 大
    for (int i = 0; i < n; ++i) {
        int x, y, w;
        // cin >> x >> y >> w;
        scanf("%d%d%d", &x, &y, &w);
        grid[++x][++y] += w;
        xx = max(xx, x);
        yy = max(yy, y);
    }

    for (int i = 1; i <= xx; ++i) {
        for (int j = 1; j <= yy; ++j) {
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
    }
    int ans = 0;
    if (r > 5000) ans = grid[xx][yy];
    else {
        for (int i = r; i <= xx; ++i) {
            for (int j = r; j <= yy; ++j) {
                ans = max(ans, grid[i][j] - grid[i - r][j] - grid[i][j - r] + grid[i - r][j - r]);
            }
        }
    }
    // cout << ans << endl;
    printf("%d", ans);
}