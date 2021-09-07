#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// const int N = 1e5 + 10;
// const int M = 3e5 + 10;
// int a[N], b[M];
int h[37];
int f[37], g[37];

void init() {
    for (int i = 0; i < 36; ++i) {
        h[(1ll << i) % 37] = i;
    }
}

inline int log2(int n) {
    return h[n % 37];
}

int main() {
    init();

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        for (int j = 0; a; ++j) {
            // cout << "a[" << i << "] = " << a << endl;
            if (a & 1) f[j]++;
            a >>= 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;

        g[log2(b)]++;
    }

    // sort(a, a + n), sort(b, b + m);

    int ans = 0;

    int i = 0, j = 0;

    while (i <= 30 && j <= 30) {
        while (i < j) ++i;

        if (f[i] == 0) {
            ++i;
            continue;
        }

        if (g[j] == 0) {
            ++j;
            continue;
        }

        int k = 1 << (i - j);
        ll c = (ll)k * f[i];
        ll d = min((ll)g[j], c);

        ans += d;
        g[j] -= d;
        f[i] -= (d + k - 1) / k;

        int rem = d % k;

        if (rem != 0) {
            int val = k - rem;

            for (int x = 0; val; ++x, val >>= 1) {
                if (val & 1) f[j + x]++;
            }

            i = j;
        }

        // cout << "f[" << i << "] = " << f[i] << " g[" << j << "] = " << g[j] << endl;

        
    }

    cout << ans << endl;
}