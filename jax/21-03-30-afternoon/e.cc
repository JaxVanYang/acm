#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int a[maxn];

int quick(int k) {
    int ret = 1;
    int tmp = 2;
    while (k) {
        if (k & 1) ret = (ll)ret * tmp % mod;
        tmp = (ll)tmp * tmp % mod;
        k >>= 1;
    }
    return ret;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    sort(a, a + n);
    a[n] = 2 * mod; // 要使用一个足够大的数，让 r 一定能停在 n
    int r = 0;
    int ans = 0;
    for (int l = 0; l < n; ++l) {
        while (a[r] - a[l] <= m) ++r;
        ans = (ans + quick(r - l - 1)) % mod;
    }
    printf("%d", ans);
}