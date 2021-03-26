#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
int a[maxn];
ll b[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) b[i] = a[i] - a[i - 1];
    ll p = 0, q = 0;
    // 只用判断从 b[2:n+1] 的差分为零就能保证原数组的元素均相等
    // 所以我们从 2 开始
    for (int i = 2; i <= n; ++i) if (b[i] >= 0) p += b[i]; else q -= b[i];
    ll ans = max(p, q);
    ll cnt = abs(p - q) + 1;
    printf("%lld\n%lld\n", ans, cnt);
}