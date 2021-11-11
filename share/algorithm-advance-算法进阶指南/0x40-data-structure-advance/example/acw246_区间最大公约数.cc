#include <iostream>
#include <algorithm>
#include <queue>
using ll = long long;

const int N = 5e5 + 10, M = N << 2;
ll a[N], diff[N], sum[N], gcd[M];
int n, m;

inline int lowbit(int x) { return x & -x; }

ll query_a(int i) {
    ll ret = 0;
    for (; i; i -= lowbit(i)) ret += sum[i];
    return ret;
}

void add_sum(int i, ll d) {
    for (; i <= n; i += lowbit(i)) {
        sum[i] += d;
    }
}

inline int avg(int a, int b) { return (a + b) >> 1; }

inline void pushup(int p, int lson, int rson) { gcd[p] = std::__gcd(gcd[lson], gcd[rson]); }

void build(int s = 1, int t = n, int p = 1) {
    if (s == t) {
        gcd[p] = diff[s];
        return;
    }
    int mid = avg(s, t);
    int lson = p << 1, rson = lson | 1;
    build(s, mid, lson);
    build(mid + 1, t, rson);
    pushup(p, lson, rson);
}

void add_gcd(int l, ll d, int s = 1, int t = n, int p = 1) {
    // std::cout << "s = " << s << " t = " << t << std::endl;
    if (s == t) {
        // std::cout << "s = " << s << " l = " << l << std::endl;
        gcd[p] += d;
        return;
    }
    int mid = avg(s, t);
    int lson = p << 1, rson = lson | 1;
    if (l <= mid) add_gcd(l, d, s, mid, lson);
    else add_gcd(l, d, mid + 1, t, rson);
    pushup(p, lson, rson);
}

ll query_gcd(int l, int r, int s = 1, int t = n, int p = 1) {
    if (l <= s && t <= r) {
        return gcd[p];
    }
    int mid = avg(s, t);
    int lson = p << 1, rson = lson | 1;
    ll ret = 0;
    if (l <= mid) ret = query_gcd(l, r, s, mid, lson);
    if (mid < r) ret = std::__gcd(ret, query_gcd(l, r, mid + 1, t, rson));
    // std::cout << "s = " << s << " t = " << t << " ret = " << ret << std::endl;
    return ret;
}

// void bfs() {
//     std::queue<std::pair<int, std::pair<int, int>>> q;
//     q.push({1, {1, n}});
//     while (q.size()) {
//         int len = q.size();
//         while (len--) {
//             auto [p, x] = q.front();
//             q.pop();
//             auto [s, t] = x;
//             // std::cout << "(" << s << ", " << t << ", " << gcd[p] << ") ";
//             if (s != t) {
//                 int mid = avg(s, t);
//                 q.push({p << 1, {s, mid}});
//                 q.push({p << 1 | 1, {mid + 1, t}});
//             }
//         }
//         // std::cout << std::endl;
//     }
// }

void solve() {
    char op[2];
    int l, r;
    ll d;
    scanf("%s%d%d", op, &l, &r);
    // std::cout << "op = " << op << " l = " << l << " r = " << r << std::endl;

    if (op[0] == 'C') {
        scanf("%lld", &d);
        add_sum(l, d);
        add_gcd(l, d);
        if (r < n) {
            add_sum(r + 1, -d);
            add_gcd(r + 1, -d);
        }
    } else {
        ll x = query_a(l);
        ll y = l < r ? query_gcd(l + 1, r) : 0;
        // std::cout << "x = " << x << " y = " << y << std::endl;
        ll ans = std::__gcd(x, y);
        if (ans < 0) ans = -ans;
        printf("%lld\n", ans);
    }

    // bfs();
    // for (int i = 1; i <= n; ++i) {
    //     std::cout << query_a(i) - query_a(i - 1) << ' ';
    // }
    // std::cout << std::endl << std::endl;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
        diff[i] = a[i] - a[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        sum[i] = diff[i];
        int low = lowbit(i);
        for (int t = 1; t < low; t <<= 1) {
            sum[i] += sum[i - t];
        }
    }

    build();

    while (m--) {
        solve();
    }

    return 0;
}