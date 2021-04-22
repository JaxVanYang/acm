#include <iostream>
using namespace std;
using ll = long long;

void solve() {
    int k, n, a, b;
    scanf("%d%d%d%d", &k, &n, &a, &b);
    int ans;
    ll up = k - (ll)n * b;
    if (up <= 0) {
        puts("-1");
        return;
    }
    int down = a - b;
    if (up % down) {
        ans = up / down;
    } else {
        ans = up / down - 1;
    }
    ans = min(ans, n);
    printf("%d\n", ans);
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        solve();
    }
}