#include <iostream>
#include <cstring>

using ll = long long;

const int N = 2e5 + 10, M = 1e6 + 10;
bool is_prime[M];
int a[N];

void init() {
    for (int i = 2; i < M; ++i) {
        is_prime[i] = true;
        for (int j = 2; j <= i / j; ++j) {
            if (i % j == 0) {
                is_prime[i] = false;
                break;
            }
        }
    }
}
int cnt_1 = 0, cnt_prime = 0, cnt_non_prime = 0;

inline bool valid() {
    return cnt_1 >= 0 && cnt_prime == 1 && cnt_non_prime == 0;
}

void solve() {
    int n, e;
    scanf("%d%d", &n, &e);

    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!is_prime[a[i]]) continue;
        int l = 1, r = 1;
        while (i - l * e >= 0 && a[i - l * e] == 1) ++l;    
        while (i + r * e < n && a[i + r * e] == 1) ++r;

        ans += (ll)l * r - 1;
    }

    printf("%lld\n", ans);
}

int main() {
    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}