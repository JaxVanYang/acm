#include <iostream>
#include <vector>
using namespace std;

const int maxn = 2e3 + 5;
const int mod = 998244353;
int dp[maxn][maxn];
int w[maxn];
vector<int> edges[maxn];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[v].push_back(u);
    }

    dp[1][k] = 1;
    if (w[1] <= k) {
        dp[1][k - w[1]] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int pre : edges[i]) {
            for (int rem = 0; rem <= k; ++rem) {
                if (dp[pre][rem] != 0) {
                    dp[i][rem] = (dp[i][rem] + dp[pre][rem]) % mod;
                    if (rem >= w[i]) {
                        dp[i][rem - w[i]] = (dp[i][rem - w[i]] + dp[pre][rem]) % mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = (ans + dp[n][i]) % mod;
    }
    printf("%d\n", ans);
}