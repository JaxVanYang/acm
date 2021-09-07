#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 9901;

int quick(int p, int k) {
    int ret = 1;

    p %= mod;

    while (k) {
        if (k & 1) {
            ret = ret * p % mod;
        }

        k >>= 1;

        p = p * p % mod;
    }

    return ret;
}

inline int inv(int p) {
    return quick(p, mod - 2);
}

int calc(int p, int k) {
    int ret;

    if ((p - 1) % mod == 0) {
        return k;
    }

    return (ll)(quick(p, k) - 1 + mod) % mod * inv(p - 1) % mod;
}

int main() {
    int a, b;
    cin >> a >> b;

    if (a == 0) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;

    for (int i = 2; i <= a / i; ++i) {
        if (a % i == 0) {
            int c = 0;

            while (a % i == 0) {
                a /= i;
                ++c;
            }

            ans = (ll)ans * calc(i, b * c + 1) % mod;
        }
    }

    if (a > 1) {
        ans = (ll)ans * calc(a, b + 1) % mod;
    }

    cout << ans << endl;
}