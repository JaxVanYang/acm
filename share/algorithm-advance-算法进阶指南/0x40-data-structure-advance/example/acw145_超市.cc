#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

template<typename T> void read(T &t) {
    t = 0; int k = -1;
    char ch = getchar();
    while (ch <= ' ') ch = getchar();
    if (ch == '-') k = 1, ch = getchar();
    while (isdigit(ch)) t = t * 10 - ch + '0', ch = getchar();
    t *= k;
}
template<typename T, typename ...Args> void read(T &t, Args &...args) {
    read(t), read(args...);
}

const int N = 1e4 + 10;
int n, id[N];
pair<int, int> ps[N];

int find(int p) {
    if (id[p] != p) {
        id[p] = find(id[p]);
    }
    return id[p];
}

void solve() {
    int maxd = 0;
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        read(ps[i].first, ps[i].second);
        maxd = max(maxd, ps[i].second);
    }

    sort(ps, ps + n, greater<pair<int, int>>());

    for (int i = 1; i <= maxd; ++i) {
        id[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        auto [p, d] = ps[i];

        int r = find(d);

        if (r > 0) {
            ans += p;
            id[r] = r - 1;
        }
    }

    printf("%lld\n", ans);
}

int main() {
    while (~scanf("%d", &n)) {
        solve();
    }
}