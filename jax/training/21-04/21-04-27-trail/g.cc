#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 4;
int a[maxn];
int dp[maxn][101][51];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    dp[0][a[0]][1] = a[0];
    // 通过 a[i] 放入的组别可以遍历所有的状态
    for (int i = 1; i < n; ++i) {
        // 遍历最后一组 gcd 的可能取值
        for (int g = 1; g <= 100; ++g) {
            int tmp = __gcd(g, a[i]);
            // 遍历 a[i] 可放入的组
            for (int j = 1; j <= min(i + 1, k); ++j) {
                if (dp[i - 1][g][j]) {
                    // 加入第 j 组
                    dp[i][tmp][j] = max(dp[i][tmp][j], dp[i - 1][g][j] - g + tmp);
                }
                if (dp[i - 1][g][j - 1]) {
                    // a[i] 作为新的第 j 组
                    dp[i][a[i]][j] = max(dp[i][a[i]][j], dp[i - 1][g][j - 1] + a[i]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 100; ++i) {
        ans = max(ans, dp[n - 1][i][k]);
    }
    printf("%d\n", ans);
}