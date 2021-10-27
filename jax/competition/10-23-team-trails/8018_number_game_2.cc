#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7, N = 1e6 + 10;
int n;
ll a[N];
int fac[N], bit[N];

ll quick(ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ret;
}

inline ll inv(ll x) {
    return quick(x, mod - 2);
}

void init() {
    fac[0] = bit[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (ll)fac[i - 1] * i % mod;
    }
    bit[1] = inv(2);
    for (int i = 2; i <= n; ++i) {
        bit[i] = (ll)bit[i - 1] * bit[1] % mod;
    }
}

ll calc(int x, int cnt) {
    ll ret = (ll)fac[cnt] * fac[n - x] % mod;
    ret = ret * inv(fac[x]) % mod * inv(fac[cnt - x]) % mod;
    ret = ret * bit[cnt - x] % mod;
    return ret;
}

int main() {
    scanf("%d", &n);
    init();

    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }

    sort(a, a + n);

    int cnt = 0, l = 0;
    while (l < n) {
        int r = l + 1;
        while (r < n && a[r] == a[l]) ++r;
        if (r - l == 2) ++cnt;
        l = r;
    }

    ll ans = (ll)fac[n] * bit[cnt] % mod;

    for (int i = 1; i <= cnt; ++i) {
        if (i & 1) {
            ans = (ans + mod - calc(i, cnt)) % mod;
        } else {
            ans = (ans + calc(i, cnt)) % mod;
        }
    }

    printf("%lld\n", ans);
}