#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
int n, k;

int power(int n, int k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = (ll)ret * n % mod;
        k >>= 1;
        n = (ll)n * n % mod;
    }
    return ret;
}

void solve() {
    if (k == 0) {
        cout << 1 << endl;
        return;
    }

    ll ans;
    ll mi = power(2, n - 1);
    ll up = (mi + 1ll) % mod;
    ll down = (mi - 1ll + mod) % mod;
    ll im = 2ll * mi % mod;
    // cout << "mi = " << mi << " up = " << up << " down = " << down << " im = " << im << endl;
    if (n & 1) {
        ans = power(up, k);
    } else {
        ans = mi;
        int base = im;
        for (int i = 1; i < k; ++i) {
            // cout << "ans = " << ans << endl;
            ans = ((ll)ans * down % mod + base) % mod;
            base = (ll)base * im % mod;
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        solve();
    }
}