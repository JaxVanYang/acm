#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
int a[maxn];

struct Tree {
    int l, r;
    ll val;
} t[maxn * 4];

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if (l == r) {
        if (l & 1) t[p].val = a[l]; // 奇数位存放正值
        else t[p].val = -a[l];      // 偶数维存放负值
        return;
    }
    int mid = l + (r - l) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    t[p].val = t[p * 2].val + t[p * 2 + 1].val;
}

void change(int p, int x, int v) {
    if (t[p].l == t[p].r) {
        if (x & 1) t[p].val = v;
        else t[p].val = -v;
        return;
    }
    int mid = t[p].l + (t[p].r - t[p].l) / 2;
    if (x <= mid) change(p * 2, x, v);
    else change(p * 2 + 1, x, v);
    t[p].val = t[p * 2].val + t[p * 2 + 1].val;
}

ll ask(int p, int l, int r) {
    if (l <= t[p].l && t[p].r <= r) return t[p].val;
    int mid = t[p].l + (t[p].r - t[p].l) / 2;
    ll ret = 0;
    if (l <= mid) ret += ask(p * 2, l, r);
    if (mid < r) ret += ask(p * 2 + 1, l, r);
    return ret;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    build(1, 1, n);
    while (q--) {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op & 1) {
            ll ans = ask(1, l, r);
            if (l & 1) printf("%lld\n", ans);
            else printf("%lld\n", -ans);
        } else {
            change(1, l, r);
        }
    }
}