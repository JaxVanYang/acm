#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mul(ll x, ll y, ll p) {
    ll ret = 0;

    while (y) {
        if (y & 1) {
            ret = (ret + x) % p;
        }

        y >>= 1;

        x = (x + x) % p;
    }

    return ret;
}

ll phi(ll n) {
    ll ret = n;

    for (int i = 2; i <= n / i; ++i) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;

            ret = ret / i * (i - 1);
        }
    }

    if (n > 1) {
        ret = ret / n * (n - 1);
    }

    return ret;
}

ll quick(ll x, ll y, ll p) {
    ll ret = 1 % p;

    while (y) {
        if (y & 1) {
            ret = mul(ret, x, p);
        }

        y >>= 1;
        x = mul(x, x, p);
    }

    return ret;
}

ll solve(int l) {
    ll ret = INT64_MAX;

    int d = __gcd(l, 8);

    ll n = l / d * 9ll;

    ll y = phi(n);

    for (int i = 1; i <= y / i; ++i) {
        if (y % i != 0) continue;

        if (quick(10, i, n) == 1) return i;

        if (quick(10, y / i, n) == 1) ret = min(ret, y / i);
    }

    if (ret == INT64_MAX) ret = 0;

    return ret;
}

int main() {
    int l;
    for (int i = 1; cin >> l && l; ++i) {
        cout << "Case " << i << ": " << solve(l) << endl;
    }
}