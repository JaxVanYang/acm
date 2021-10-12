#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int a[N], b[N];
ll dp[N][3];

inline void reset(int n) {
    memset(dp[1], 0x3f, 3 * n * sizeof(ll));
}

void solve() {
    int n;
    scanf("%d", &n);
    reset(n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", a + i, b + i);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            // cout << dp[i][j] << ' ';
            for (int k = 0; k < 3; ++k) {
                if (a[i - 1] + j != a[i] + k) {
                    dp[i][k] = min(dp[i][k], b[i] * k + dp[i - 1][j]);
                }
            }
        }
        // cout << endl;
    }

    ll ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
    printf("%lld\n", ans);
}

int main() {
    a[0] = -100;

    int q;
    scanf("%d", &q);

    while (q--) {
        solve();
    }
}