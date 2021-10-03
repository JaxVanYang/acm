#include <iostream>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;
int a[N], s[N], t[N];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);

        a[i] %= 3;
        s[i] = (s[i - 1] + a[i]) % 3;
        t[i] = (t[i - 1] + a[i] * a[i]) % 3;
    }

    int dp[3][3] = {};
    dp[0][0] = 1;

    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                int t1 = s[i] - j, t2 = t[i] - k;
                t1 *= t1;

                if ((t1 - t2) % 3 == 0) {
                    ans += dp[j][k];
                }
            }
        }

        dp[s[i]][t[i]]++;
    }

    printf("%lld\n", ans);
}