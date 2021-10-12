#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define REP(i, l, r) for (int i = l; i < r; ++i)
#define F first
#define S second
#define PF push_fornt
#define PB push_back
#define MP make_pair

const char el = '\n';
const int N = 2e5 + 10;
int a[N];

void solve() {
    int n;
    scanf("%d", &n);

    ll sum = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        sum += a[i];
    }

    if (sum * 2 % n) {
        puts("0");
        return;
    }

    sort(a, a + n);

    ll avg = sum * 2 / n;

    // cout << "avg = " << avg << endl;

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        auto [l, r] = equal_range(a + i + 1, a + n, avg - a[i]);

        // cout << "target = " << avg - a[i] << endl;

        // cout << "l = " << lId << " r = " << rId << endl;

        ans += r - l;
    }

    printf("%lld\n", ans);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    // cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
