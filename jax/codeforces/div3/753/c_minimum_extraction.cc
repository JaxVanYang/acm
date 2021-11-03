#include <iostream>
#include <algorithm>
using ll = long long;

const int N = 2e5 + 20;
ll a[N];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }
    std::sort(a, a + n);

    ll ans = a[0];
    for (int i = 1; i < n; ++i) {
        ans = std::max(ans, a[i] - a[i - 1]);
    }
    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}