#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int mod = 998244353;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) scanf("%d", b + i);
    sort(a, a + n);
    sort(b, b + n), reverse(b, b + n);
    int ans = 0;
    auto f = [](int l, int r) {
        int ret = 0;
        for (int i = l; i <= r; ++i) {
            ret = ((ll)ret + (ll)a[i] * b[i] % mod) % mod;
        }
        return ret;
    };
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ans = ((ll)ans + (ll)f(i, j)) % mod;
        }
    }
    printf("%d", ans);
}