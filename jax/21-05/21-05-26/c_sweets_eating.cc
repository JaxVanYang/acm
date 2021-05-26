#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 10;
int a[maxn];
ll sum[maxn], ans[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + a[i];
    }
    // 将第一天分出来考虑，然后以一天为单位考虑动态规划就能很容易地写出转移方程
    for (int i = 0; i < m; ++i) {
        ans[i] = sum[i + 1];
    }
    for (int i = m; i < n; ++i) {
        ans[i] = ans[i - m] + sum[i + 1];
    }
    for (int i = 0; i < n; ++i) {
        printf("%lld ", ans[i]);
    }
}