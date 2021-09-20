#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
pair<int, int> ps[N];

void solve() {
    ll a, b, r;
    // cin >> a >> b >> r;
    scanf("%lld%lld%lld", &a, &b, &r);

    double ans = (b - r) * (b - r) + a * a;
    ans = sqrt(ans);
    ans *= 2;
    ans -= r;

    if (r >= b) {
        ans = 2 * a - r;
    }

    // cout << setprecision(2) << ans << endl;
    printf("%.2lf\n", ans);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit);

    int t;
    // cin >> t;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        printf("Case #%d: ", i);
        solve();
    }
}