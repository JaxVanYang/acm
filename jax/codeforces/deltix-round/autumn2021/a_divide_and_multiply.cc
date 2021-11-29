#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>

using ll = long long;

const int N = 16;
ll a[N];

int count(ll &x) {
    int ret = 0;
    while (x % 2 == 0) {
        x >>= 1;
        ++ret;
    }
    return ret;
}

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }

    int c = 0;
    for (int i = 0; i < n; ++i) {
        c += count(a[i]);
    }

    std::sort(a, a + n);
    a[n - 1] <<= c;

    ll ans = std::accumulate(a, a + n, 0ll);
    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    
}