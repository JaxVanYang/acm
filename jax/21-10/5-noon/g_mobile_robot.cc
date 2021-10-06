#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
const ll inf = INT64_MAX / 4;

template<typename T>
void read(T &t) {
    t = 0; int k = 1;
    char ch = getchar();
    if (ch == '-') {
        k = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        t = t * 10 + ch - '0';
        ch = getchar();
    }
    t *= k;
}
template<typename T, typename ...Args>
void read(T &t, Args &...args) {
    read(t), read(args...);
}

int main() {
    int n;
    ll d;
    read(n, d);
    // cout << "n = " << n << " d = " << d << endl;

    ll min1 = inf, max1 = -inf, min2 = min1, max2 = max1;
    for (int i = 0; i < n; ++i) {
        ll x;
        read(x);
        ll val1 = x - i * d, val2 = x - (n - i) * d;
        // cout << "val1 = " << val1 << " val2 = " << val2 << endl;
        min1 = min(min1, val1), max1 = max(max1, val1);
        // cout << "min1 = " << min1 << " max1 = " << max1 << endl;
        min2 = min(min2, val2), max2 = max(max2, val2);
    }

    ll ans = min(max1 - min1, max2 - min2);
    if (ans & 1) {
        printf("%lld.5\n", ans / 2);
    } else {
        printf("%lld.0\n", ans / 2);
    }
}