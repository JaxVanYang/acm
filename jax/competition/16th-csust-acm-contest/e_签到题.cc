#include <iostream>
#include <bitset>
using namespace std;

template<typename T> void read(T &t) {
    t = 0; int k = -1;
    char ch = getchar();
    while (ch <= ' ') ch = getchar();
    if (ch == '-') k = 1, ch = getchar();
    while (isdigit(ch)) t = t * 10 - ch + '0', ch = getchar();
    t *= k;
}
template <typename T, typename ...Args> void read(T &t, Args &...args) { read(t), read(args...); }

const int N = 2e5 + 10, M = 60;
int n, m;
int a[N];
bitset<M> is_p, mask;

struct Seg {
    int l, r;
    bitset<M> mark;
    int add;
} tree[N * 4];

void build(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
        tree[p].mark[a[l]] = true;
        // cout << "p = " << p << " id = " << l << endl
            //  << tree[p].mark << endl;
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    tree[p].mark = tree[p << 1].mark | tree[p << 1 | 1].mark;
}

void change(bitset<M> &mark, int val) {
    mark = (mark << val) | (mark >> (m - val));
    mark &= mask;
}

void spread(int p) {
    if (tree[p].add) {
        int val = tree[p].add;
        tree[p].add = 0;
        change(tree[p << 1].mark, val), change(tree[p << 1 | 1].mark, val);

        tree[p << 1].add = (tree[p << 1].add + val) % m;
        tree[p << 1 | 1].add = (tree[p << 1 | 1].add + val ) % m;
    }
}

void update(int p, int l, int r, int val) {
    if (l <= tree[p].l && tree[p].r <= r) {
        change(tree[p].mark, val);
        tree[p].add = (tree[p].add + val) % m;
        return;
    }
    spread(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if (l <= mid) update(p << 1, l, r, val);
    if (mid < r) update(p << 1 | 1, l, r, val);
    tree[p].mark = tree[p << 1].mark | tree[p << 1 | 1].mark;
}

bitset<M> query(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        // cout << "p = " << p << " l = " << tree[p].l << " r = " << tree[p].r << endl;
        // cout << tree[p].mark << endl;
        return tree[p].mark;
    }

    spread(p);
    bitset<M> res;
    int mid = tree[p].l + tree[p].r >> 1;
    if (l <= mid) res |= query(p << 1, l, r);
    if (mid < r) res |= query(p << 1 | 1, l, r);
    return res;
}

void init() {
    for (int i = 2; i < m; ++i) {
        is_p[i] = true;
        for (int j = 2; j <= i / j; ++j) {
            if (i % j == 0) {
                is_p[i] = false;
                break;
            }
        }
    }
    for (int i = 0; i < m; ++i) mask[i] = true;
}

void solve() {
    int op, l, r, val;
    read(op, l, r);

    if (op == 1) {
        read(val);
        update(1, l, r, val);
    } else {
        auto res = query(1, l, r);
        // cout << "res = " << res << endl;
        auto ans = res & is_p;
        printf("%lld\n", ans.count());
    }
}

int main() {
    read(n, m);
    init();
    // cout << is_p << endl;

    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        a[i] %= m;
    }

    build(1, 1, n);

    int q;
    read(q);

    while (q--) {
        solve();
    }
}