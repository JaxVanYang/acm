#include <iostream>
using namespace std;
using ll = long long;

const ll maxn = 1e12;
int p[3], n[3], e[3];   // 初始点数，每级点数，升点所需金币

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll m;
        scanf("%lld%d%d%d", &m, p, p + 1, p + 2);
        scanf("%d%d%d", n, n + 1, n + 2);
        scanf("%d%d%d", e, e + 1, e + 2);
        ll l = 0, r = maxn;
        while (l < r) {
            ll mid = (l + r + 1) / 2;
            ll need[3];
            for (int i = 0; i < 3; ++i) need[i] = (mid * n[i] - p[i]) * e[i];
            ll total = 0;
            for (int i = 0; i < 3; ++i) if (need[i] > 0) total += need[i];
            if (m == total) {
                l = mid;
                break;
            }
            if (m < total) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        printf("%lld\n", l);
    }
}