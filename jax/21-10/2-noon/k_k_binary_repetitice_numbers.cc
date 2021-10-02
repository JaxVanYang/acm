#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
int ps[30], tot = 0;
int h[37];

inline int lowbit(int x) {
    return x & -x;
}

inline int log(int x) {
    return h[x % 37];
}

ll quick(ll x, ll y) {
    ll ret = 1;

    while (y) {
        if (y & 1) {
            ret = ret * x % mod;
        }

        x = x * x % mod;
        y >>= 1;
    }

    return ret;
}

void solve() {
    tot = 0;
    
    int k;
    scanf("%d", &k);
    int tmp = k;

    ll ans = 0;

    for (int i = 2; i <= k / i; ++i) {

        // cout << "i = " << i << endl;
        if (k % i == 0) {
            while (k % i == 0) {
                k /= i;
            }

            ps[tot] = tmp / i;
            // ans = (ans + quick(2, ps[tot])) % mod;
            ++tot;
        }
    }

    if (k > 1) {
        ps[tot] = tmp / k;
        // ans = (ans + quick(2, ps[tot])) % mod;
        ++tot;
    }

    for (int mask = 1; mask < (1 << tot); ++mask) {
        int c = 0;
        int t = mask;
        int val = 0;

        for (; t; ++c) {
            int low = lowbit(t);

            val = __gcd(val, ps[log(low)]);

            t -= low;
        }

        // if (c <= 1) {
        //     continue;
        // }

        if (c & 1) {
            ans = (ans + quick(2, val)) % mod;
        } else {
            ans = (ans + mod - quick(2, val)) % mod;
        }
    }

    printf("%lld\n", ans);
}

void init() {
    for (int i = 0; i < 36; ++i) {
        h[(1ll << i) % 37] = i;
    }
}

int main() {
    init();

    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }
}