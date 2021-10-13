#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// inline ll count(ll x, ll n) {
//     return n / x;
// }

ll phi(ll n, ll k) {
    ll ret = n;

    for (int i = 2; i <= k / i; ++i) {
        if (k % i == 0) {
            while (k % i == 0) {
                k /= i;
            }

            ret = ret / i * (i - 1);
        }
    }

    if (k > 1) {
        ret = ret / k * (k - 1);
    }

    return ret;
}

void solve() {
    ll a, m;
    cin >> a >> m;

    ll d = __gcd(a, m);

    ll k = m / d, t = a / d;

    ll lmt = k + t - 1;

    ll ans = phi(lmt, k) - phi(t - 1, k);

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}