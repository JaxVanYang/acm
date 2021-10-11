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
const int N = 1e6 + 10;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    // cin.exceptions(cin.failbit);

    ll x, y, m;
    scanf("%lld%lld%lld", &x, &y, &m);

    if (x > y) {
        swap(x, y);
    }

    if (y >= m) {
        puts("0");
        return 0;
    }

    if (y <= 0) {
        puts("-1");
        return 0;
    }

    ll ans = 0;

    if (x < 0) {
        ans = (-x + y - 1) / y;
        x += ans * y;
    }

    ll a[2] = {x, y};

    int pre = 0, cur = 1;

    while (a[cur] < m) {
        a[pre] += a[cur];
        pre ^= 1;
        cur ^= 1;
        ++ans;
    }

    printf("%lld\n", ans);
}
