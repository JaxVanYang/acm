#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

const int maxn = 12;
const int mod = 1e9 + 7;
int grid[maxn][maxn];
int dp[maxn][1 << maxn];
int n, m;

bool valid(int x, int row) {
    for (int i = 0; i < m; ++i) {
        if (((x >> i) & 1 ) && !grid[row][i]) return false;
    }
    int pre = 0;
    while (x) {
        if (pre && (x & 1)) return false;
        pre = x & 1;
        x >>= 1;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &grid[i][j]);
            }
        }
        // memset(dp, 0, sizeof dp);
        for (int i = 0; i < 1 << m; ++i) {
            if (valid(i, 0)) dp[0][i] = 1;
            else dp[0][i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 1 << m; ++j) {
                dp[i][j] = 0;
                if (valid(j, i)) {
                    for (int k = 0; k < 1 << m; ++k) {
                        if ((j & k) == 0) { // 注意 & 的优先级低于 ==，所以要加括号
                            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                        }
                    }
                }
            }
        }

        // cout << "dp :" << endl;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < 1 << m; ++j) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }


        int ans = 0;
        for (int i = 0; i < 1 << m; ++i) ans = (ans + dp[n - 1][i]) % mod;
        printf("%d\n", ans);
    }
    return 0;
}