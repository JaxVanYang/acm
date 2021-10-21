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
template<typename T, typename ...Args> void read(T &t, Args &...args) { read(t), read(args...); }

const int N = 2e5 + 10, M = 60;
int n, m, a[N];
bitset<M> is_p, mask;

inline void change(bitset<M> &mark, int val) {
    mark = (mark << val) & mask | (mark >> (m - val));
}

struct Seg {
    int add;
    bitset<M> mark;
} tree[N << 2];

void pushdown(int p) {
    if (tree[p].add) {
        int &add = tree[p].add;
        int pl = p << 1, pr = pl | 1;
        change(tree[pl].mark, add);
        change(tree[pr].mark, add);

        tree[pl].add = (tree[pl].add + add) % m;
        tree[pr].add = (tree[pr].add + add) % m;
        add = 0;
    }
}

inline void pushup(int p) {
    tree[p].mark = tree[p << 1].mark | tree[p << 1 | 1].mark;
}

void build(int p, int l, int r) {
    if (l == r) {
        tree[p].mark[a[l]] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    pushup(p);
}

void update(int p, int cl, int cr, int l, int r, int val) {
    if (l <= cl && cr <= r) {
        change(tree[p].mark, val);
        tree[p].add = (tree[p].add + val) % m;
        return;
    }
    pushdown(p);
    int mid = (cl + cr) >> 1;
    if (l <= mid) update(p << 1, cl, mid, l, r, val);
    if (mid < r) update(p << 1 | 1, mid + 1, cr, l, r, val);
    pushup(p);
}

bitset<M> query(int p, int cl, int cr, int l, int r) {
    if (l <= cl && cr <= r) {
        return tree[p].mark;
    }
    pushdown(p);
    bitset<M> ret;
    int mid = (cl + cr) >> 1;
    if (l <= mid) ret |= query(p << 1, cl, mid, l, r);
    if (mid < r) ret |= query(p << 1 | 1, mid + 1, cr, l, r);
    return ret;
}

void init() {
    for (int i = 0; i < m; ++i) {
        mask[i] = 1;
    }
    for (int i = 2; i < m; ++i) {
        is_p[i] = 1;
        for (int j = 2; j <= i / j; ++j) {
            if (i % j == 0) {
                is_p[i] = 0;
                break;
            }
        }
    }
    for (int i = 0; i < m; ++i) mask[i] = true;
}

int main() {
    read(n, m);
    init();

    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        a[i] %= m;
    }

    build(1, 1, n);

    int q;
    read(q);

    while (q--) {
        int op, l, r, val;
        read(op, l, r);

        if (op == 1) {
            read(val);
            val %= m;
            update(1, 1, n, l, r, val);
        } else {
            auto res = query(1, 1, n, l, r);
            auto ans = res & is_p;
            printf("%zu\n", ans.count());
        }
    }
}