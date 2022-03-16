#include <iostream>

using ll = long long;

const int N = 105;
int a[N];
int n;

ll calc(ll k) {
    ll ret = k;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i + 1] - a[i] > k) {
            ret += k;
        } else {
            ret += a[i + 1] - a[i];
        }
    }
    return ret;
}

void solve() {
    ll h;
    scanf("%d%lld", &n, &h);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    ll l = 1, r = 1e18;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (calc(mid) >= h) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    printf("%lld\n", l);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}