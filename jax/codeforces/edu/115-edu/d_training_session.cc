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

template<typename T> void read(T &t) {
    t = 0;
    int k = 1;
    char ch = getchar();
    if (ch == '-') {
        ch = getchar();
        k = -1;
    }
    while (isdigit(ch)) {
        t = 10 * t + ch - '0';
        ch = getchar();
    }
    t *= k;
}
template<typename T, typename ...Args> void read(T &t, Args &...args) {
    read(t), read(args...);
}

const char el = '\n';
const int N = 2e5 + 10;
int a[N], b[N];

void solve() {
    int n;
    read(n);

    map<int, int> cntA, cntB;

    for (int i = 0; i < n; ++i) {
        read(a[i], b[i]);
        ++cntA[a[i]], ++cntB[b[i]];
    }

    ll ans = (ll)n * (n - 1) * (n - 2) / 6;

    for (int i = 0; i < n; ++i) {
        ans -= (cntA[a[i]] - 1ll) * (cntB[b[i]] - 1ll);
    }

    printf("%lld\n", ans);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    // cin.exceptions(cin.failbit);

    int t;
    read(t);
    while (t--) {
        solve();
    }
}
