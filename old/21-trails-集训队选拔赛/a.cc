#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 5005;
// 花费不会爆 int，而价值会
int id[maxn], cost[maxn];
ll val[maxn];
ll v[maxn];
int w[maxn];
ll dp[2][maxn];
bool st[maxn];

int find(int p) {
    if (id[p] != p) id[p] = find(id[p]);
    return id[p];
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    // 初始化并查集
    for (int i = 1; i <= n; ++i) id[i] = i;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%d", val + i, cost + i);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        int xId = find(x), yId = find(y);
        if (xId != yId) {   // 不在同一个连通分量中的时候才更新，否则会错误增加分量对应的价值和花费
            id[xId] = yId;
            val[yId] += val[xId];
            cost[yId] += cost[xId];
        }
    }

    // 去重，将每个连通分量对应的价值 v 和 花费 w 记录到数组里
    int cnt = 1;
    for (int i = 1; i <= n; ++i) {
        int iId = find(i);
        if (!st[iId]) {
            st[iId] = 1;
            v[cnt] = val[iId];
            w[cnt] = cost[iId];
            ++cnt;
        }
    }

    // 求解背包问题
    for (int i = 1; i < cnt; ++i) {
        for (int j = 0; j <= p; ++j)
            dp[i & 1][j] = dp[(i - 1) & 1][j];
        for (int j = w[i]; j <= p; ++j)
            dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1) & 1][j - w[i]] + v[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= p; ++i) ans = max(ans, dp[(cnt - 1) & 1][i]);
    cout << ans << endl;
}