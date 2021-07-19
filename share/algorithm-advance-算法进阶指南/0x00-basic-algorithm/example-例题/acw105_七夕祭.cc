#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int r[maxn], c[maxn];
int sum[maxn];
int cpy[maxn];

int main() {
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < t; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        r[x]++, c[y]++;
    }
    bool rFlag = t % n == 0, cFlag = t % m == 0;
    if (!rFlag && !cFlag) {
        puts("impossible");
        return 0;
    }
    ll ans = 0;   
    if (rFlag) {
        int dec = t / n;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + r[i] - dec;
        }
        memcpy(cpy + 1, sum + 1, sizeof(int) * n);
        sort(cpy + 1, cpy + n + 1);
        int diff = cpy[n / 2 + 1];
        for (int i = 1; i <= n; ++i) sum[i] -= diff;
        for (int i = 1; i <= n; ++i) ans += abs(sum[i]);
    }
    if (cFlag) {
        int dec = t / m;
        for (int i = 1; i <= m; ++i) {
            sum[i] = sum[i - 1] + c[i] - dec;
        }
        memcpy(cpy + 1, sum + 1, sizeof(int) * m);
        sort(cpy + 1, cpy + m + 1);
        int diff = cpy[m / 2 + 1];
        for (int i = 1; i <= m; ++i) sum[i] -= diff;
        for (int i = 1; i <= m; ++i) ans += abs(sum[i]);
    }
    if (rFlag && cFlag) {
        printf("both");
    } else if (rFlag) {
        printf("row");
    } else {
        printf("column");
    }
    printf(" %lld", ans);
}
/* 后记
 * 1 到 n 的中位数可以直接取 n / 2 + 1
 */