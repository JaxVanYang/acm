#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, m;
int a[N];

struct SegTree {
    int l, r;
    ll sum, add;
} t[N * 4];

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if (l == r) {
        t[p].sum = a[l];
        return;
    }

    int mid = l + r >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
}

void spread(int p) {
    if (t[p].add) {
        int lc = p * 2, rc = lc + 1;
        ll sum = t[p].sum, add = t[p].add;
        
        t[lc].sum +=  add * (t[lc].r - t[lc].l + 1);
        t[rc].sum += add * (t[rc].r - t[rc].l + 1);
        
        t[lc].add += add;
        t[rc].add += add;

        t[p].add = 0;
    }
}

void change(int p, int l, int r, int d) {
    if (l <= t[p].l && t[p].r <= r) {
        t[p].sum += (ll)d * (t[p].r - t[p].l + 1);
        t[p].add += d;
        return;
    }

    spread(p);
    int mid = t[p].l + t[p].r >> 1;
    if (l <= mid) {
        change(2 * p, l, r, d);
    }
    if (r > mid) {
        change(2 * p + 1, l, r, d);
    }

    t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
}

ll ask(int p, int l, int r) {
    if (l <= t[p].l && t[p].r <= r) {
        return t[p].sum;
    }

    spread(p);
    ll ret = 0;
    int mid = t[p].l + t[p].r >> 1;
    if (l <= mid) {
        ret += ask(p * 2, l, r);
    }
    if (r > mid) {
        ret += ask(p * 2 + 1, l , r);
    }

    return ret;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n);

    for (int i = 0; i < m; ++i) {
        char ch;
        cin >> ch;

        if (ch == 'C') {
            int l, r, d;
            cin >> l >> r >> d;

            change(1, l, r, d);
        } else {
            int l, r;
            cin >> l >> r;

            cout << ask(1, l , r) << endl;
        }
    }
}