#include <iostream>
#include <algorithm>

using ll = long long;

const int N = 2e5 + 10;
int n;

struct Node {
    int s, e, d;
    inline bool operator<(const Node node) {
        return s < node.s || (s == node.s && e < node.e);
    }
} nodes[N];

int calc(int p) {
    int ret = 0;
    for (int i = 0; i < n; ++ i) {
        auto &nd = nodes[i];
        if (nd.s > p) break;
        int cnt = (std::min(p, nd.e) - nd.s) / nd.d + 1;
        ret ^= cnt;
        // printf("l = %d r = %d\n", nd.s, std::min(p, nd.e));
        // printf("cnt = %d ret = %d\n", cnt, ret);
    }
    return ret;
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        auto &nd = nodes[i];
        scanf("%d%d%d", &nd.s, &nd.e, &nd.d);
    }
    std::sort(nodes, nodes + n);

    const ll lmt = (ll)nodes[n - 1].e + 1;
    // printf("lmt = %lld\n", lmt);

    ll l = 0, r = lmt;
    while (l < r) {
        // printf("l = %lld r = %lld\n", l , r);
        ll mid = l + r >> 1;
        int sum  = calc(mid);
        // printf("mid = %lld sum = %d\n", mid, sum);
        if (sum & 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (l == lmt) {
        puts("There's no weakness.");
    } else {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            auto &nd = nodes[i];
            if (nd.s > l) break;
            if ((l - nd.s) % nd.d == 0) ++cnt;
        }
        printf("%lld %d\n", l, cnt);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}