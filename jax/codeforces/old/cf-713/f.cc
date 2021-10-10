#include <iostream>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d", b + i);
        }

        ll ans = 1e18;
        ll cur = 0, val = 0;
        for (int i = 0; i < n; ++i) {
            // 技巧，使用 max 节省 if 判断
            ans = min(ans, cur + max(0ll, (c - val + a[i] - 1) / a[i]));
            // cout << "i = " << i << " ans = " << ans << endl;
            if (val >= b[i]) {
                ++cur;
            } else {
                int days = (b[i] - val + a[i] - 1) / a[i];
                val += days * a[i];
                cur += days + 1;
                // cout << "days = " << days << endl;
            }
            val -= b[i];
        }
        printf("%lld\n", ans);
    }
}