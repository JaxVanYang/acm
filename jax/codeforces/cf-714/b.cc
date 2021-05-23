#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int a[maxn];

int calc(int n) {
    int ret = 1;
    for (int i = 2; i <= n; ++i) {
        ret = (ll)ret * i % mod;
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    int res = 0xffffffff;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        res &= a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == res) {
            ++cnt;
        }
    }
    if (cnt < 2) {
        puts("0");
        return;
    }
    int left = n - 2;
    int ans = (ll)cnt * (cnt - 1) % mod;
    ans = (ll)ans * calc(left) % mod;
    printf("%d\n", ans);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}