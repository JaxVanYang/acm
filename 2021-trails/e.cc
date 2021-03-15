#include <iostream>
using namespace std;
const int maxn = 50005;
bool a[maxn];

struct Tree {
    int l, r, cnt;
    int mark = -1;  // -1 表示无需更新，0 表示升序，1 表示降序
} t[maxn * 4];

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if (l == r) {
        t[p].cnt = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    t[p].cnt = t[p * 2].cnt + t[p * 2 + 1].cnt;
}

void spread(int p) {
    if (~t[p].mark) {
        int lCnt = t[p * 2].cnt, rCnt = t[p * 2 + 1].cnt;
        int lRange = t[p * 2].r - t[p * 2].l + 1, rRange = t[p * 2 + 1].r - t[p * 2 + 1].l + 1;
        if (t[p].mark) {    // 降序，要把 1 都放在左边
            if (lCnt + rCnt <= lRange) {
                t[p * 2].cnt = lCnt + rCnt;
                t[p * 2 + 1].cnt = 0;
            } else {
                t[p * 2].cnt = lRange;
                t[p * 2 + 1].cnt = lCnt + rCnt - lRange;
            }
        } else {
            if (lCnt + rCnt <= rRange) {
                t[p * 2 + 1].cnt = lCnt + rCnt;
                t[p * 2].cnt = 0;
            } else {
                t[p * 2 + 1].cnt = rRange;
                t[p * 2].cnt = lCnt + rCnt - rRange;
            }
        }
        t[p * 2].mark = t[p].mark;
        t[p * 2 + 1].mark = t[p].mark;
        t[p].mark = -1;
    }
}

void change(int p, int l, int r, int mark) {
    if (l <= t[p].l && t[p].r <= r) {
        t[p].mark = mark;
        return;
    }
    spread(p);  // 先处理之前的标记
    int mid = (t[p].l + t[p].r) / 2;
    // 再更新子结点
    if (l <= mid) change(p * 2, l, r, mark);
    if (mid < r) change(p * 2 + 1, l, r, mark);
    // 再通过子结点更新当前结点
    t[p].cnt = t[p * 2].cnt + t[p * 2 + 1].cnt;
}

int ask(int p, int l, int r) {
    if (l <= t[p].l && t[p].r <= r) return t[p].cnt;
    spread(p);
    int mid = (t[p].l + t[p].r) / 2;
    int ret = 0;
    if (l <= mid) ret += ask(p * 2, l, r);
    if (mid < r) ret += ask(p * 2 + 1, l , r);
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    build(1, 1, n);
    while (m--) {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        change(1, l, r, op);
    }
    for (int i = 1; i <= n; ++i) printf("%d ", ask(1, i, i));
}