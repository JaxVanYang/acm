#include <iostream>
using ll = long long;

void solve() {
    ll x, n;
    scanf("%lld%lld", &x, &n);
    // std::cout << "x = " << x << " n = " << n << std::endl;

    ll begin = n - n % 4;
    // std::cout << "begin = " << begin << " n = " << n << std::endl;
    for (ll i = begin + 1; i <= n; ++i) {
        if (x & 1) {
            x += i;
        } else {
            x -= i;
        }
    }
    printf("%lld\n", x);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}