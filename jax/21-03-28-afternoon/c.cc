#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 7;

int n;
int a[maxn], b[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", b + i);
        b[i] += b[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += a[i] * (b[n] - b[i - 1]);
    }
    printf("%lld\n", ans);
}