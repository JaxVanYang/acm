#include <iostream>
#include <algorithm>

const int N = 1e4 + 10, M = N << 1, LMT = M << 2;
int n, k = 1, tot, size, cnt[LMT];
double raw[M], len[LMT];

inline int get_id(double x) {
    return std::lower_bound(raw, raw + tot, x) - raw;
}

struct Node {
    double x, y1, y2;
    int cnt;

    inline bool operator < (const Node &rhs) const {
        return x < rhs.x;
    }
} nodes[M];

inline int avg(int x, int y) {
    return (x + y) >> 1;
}

void build(int s = 1, int t = tot - 1, int p = 1) {
    len[p] = 0.0;
    cnt[p] = 0;
    if (s == t) {
        return;
    }
    int mid = avg(s, t);
    int lson = p << 1, rson = lson | 1;
    build(s, mid, lson);
    build(mid + 1, t, rson);
}

inline void pushup(int s, int t, int p, int lson, int rson) {
    if (cnt[p]) {
        len[p] = raw[t] - raw[s - 1];
    } else {
        len[p] = len[lson] + len[rson];
    }
}

void update(int l, int r, int c, int s = 1, int t = tot - 1, int p = 1) {
    int mid = avg(s, t);
    int lson = p << 1, rson = lson | 1;

    if (l <= s && t <= r) {
        cnt[p] += c;
        // std::cout << "s = " << s << " t = " << t << " len = " << len[p] << std::endl;
        if (cnt[p]) {
            len[p] = raw[t] - raw[s - 1];
        } else if (s == t) {
            len[p] = 0.0;
        } else {
            len[p] = len[lson] + len[rson];
        }
        return;
    }
    if (l <= mid) update(l, r, c, s, mid, lson);
    if (mid < r) update(l, r, c, mid + 1, t, rson);
    pushup(s, t, p, lson, rson);
    // std::cout << "s = " << s << " t = " << t << " len = " << len[p] << std::endl;
}

void solve() {
    tot = size = n << 1;
    for (int i = 0; i < n; ++i) {
        double x1, y1, x2, y2;
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        nodes[i << 1] = {x1, y1, y2, 1};
        nodes[i << 1 | 1] = {x2, y1, y2, -1};
        raw[i << 1] = y1;
        raw[i << 1 | 1] = y2;
    }

    std::sort(raw, raw + tot);
    tot = std::unique(raw, raw + tot) - raw;
    build();

    double ans = 0.0;
    std::sort(nodes, nodes + size);
    for (int i = 1; i < size; ++i) {
        double pre_x = nodes[i - 1].x;

        int l = get_id(nodes[i - 1].y1) + 1, r = get_id(nodes[i - 1].y2);
        // std::cout << "l = " << l << " r = " << r << " cnt = " << nodes[i - 1].cnt << std::endl;
        update(l, r, nodes[i - 1].cnt);

        // std::cout << "wid = " << nodes[i].x - pre_x << " len = " << len[1] << std::endl;
        ans += (nodes[i].x - pre_x) * len[1];
        // std::cout << "ans = " << ans << std::endl;
    }

    printf("Total explored area: %.2lf\n", ans);
}

int main() {
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("Test case #%d\n", k++);
        solve();
        puts("");
    }

    return 0;
}