#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;

ll calc(ll n) {
    ll ret = 0;
    for (ll i = 1; i <= n; ++i) {
        ret |= n % i;
    }
    return ret;
}

ll f(ll n) {
    if (n == 1) return 0;
    ll tmp = ceil(log2(n) - 1);
    return (1ll << tmp) - 1;
}

int main() {
    // for (int i = 1; i < 100; ++i) {
    //     // printf("%d: %lld mi = %lf f = %lld\n", i, calc(i), ceil(log2(i) - 1), f(i));
    //     ll std = calc(i), val = f(i);
    //     printf("std = %lld val = %lld\n", std, val);
    //     if (std != val) {
    //         printf("WA %d", i);
    //         exit(1);
    //     }
    // }

    // cout << f(1e12) << endl;

    int t;
    scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", f(n));
    }
}