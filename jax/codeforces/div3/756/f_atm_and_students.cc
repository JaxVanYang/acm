#include <iostream>
using ll = long long;

const int N = 2e5 + 10;
int a[N];

void solve() {
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int l = 0, r = 0, ans = 0, L = -1, R = -1;
    ll sum = 0;
    
    while (r < n) {
        r = std::max(r, l);

        while (r < n && sum + s + a[r] >= 0) {
            sum += a[r++];
        }

        // std::cout << "l = " << l << " r = " << r << " sum = " << sum << std::endl;

        if (r - l > ans) {
            ans = r - l;
            L = l, R = r;
        }
        
        if (r > l) sum -= a[l];
        ++l;
    }

    if (ans) printf("%d %d\n", L + 1, R);
    else puts("-1");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}