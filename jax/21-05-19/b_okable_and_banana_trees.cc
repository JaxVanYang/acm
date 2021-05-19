#include <iostream>
using namespace std;
using ll = long long;

inline ll calc(ll x, ll y) {
    return (x + 1) * (y + 1) * (x + y) / 2;
}

int main() {
    ll m, b;
    scanf("%lld%lld", &m, &b);
    ll ans = 0;
    for (int y = 0; y <= b; ++y) {
        ans = max(ans, calc(m * (b - y), y));
    }
    printf("%lld\n", ans);
}