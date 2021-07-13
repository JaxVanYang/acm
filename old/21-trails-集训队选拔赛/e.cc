#include <iostream>
using namespace std;

const int maxn = 5e4 + 5;

int a[maxn];
int n, m;

struct Tree {
  int l, r, cnt, mark = -1;
} t[maxn * 4];

void build(int p, int l, int r) {
  t[p].l = l, t[p].r = r;
  if (l == r) {
    t[p].cnt = a[l];
    return;
  }
  int mid = l + r >> 1;
  if (l <= mid) build(p << 1, l, mid);
  if (mid < r) build(p << 1 | 1, mid + 1, r);
  t[p].cnt = t[p << 1].cnt + t[p << 1 | 1].cnt;
}

void spread(int p) {
  if (t[p].mark == -1) return;
  Tree &l = t[p << 1], &r = t[p << 1 | 1];
  l.mark = r.mark = t[p].mark;
  l.cnt = (l.r - l.l + 1) * l.mark;
  r.cnt = (r.r - r.l + 1) * r.mark;
  t[p].mark = -1;
}

void change(int p, int l, int r, int v) {
  if (l <= t[p].l && t[p].r <= r) {
    t[p].cnt = (t[p].r - t[p].l + 1) * v;
    t[p].mark = v;
    return;
  }
  spread(p);
  int mid = t[p].l + t[p].r >> 1;
  if (l <= mid) change(p << 1, l, r, v);
  if (mid < r) change(p << 1 | 1, l, r, v);
  t[p].cnt = t[p << 1].cnt + t[p << 1 | 1].cnt;
}

int ask(int p, int l, int r) {
  if (l <= t[p].l && t[p].r <= r) return t[p].cnt;
  spread(p);
  int mid = t[p].l + t[p].r >> 1;
  int ret = 0;
  if (l <= mid) ret += ask(p << 1, l, r);
  if (mid < r) ret += ask(p << 1 | 1, l, r);
  return ret;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  build(1, 1, n);
  // for (int i = 1; i <= n; ++i) printf("%d ", ask(1, i, i));
  while (m--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    int cnt = ask(1, l, r);
    if (op) {
      change(1, l, l + cnt - 1, 1);
      change(1, l + cnt, r, 0);
    } else {
      change(1, l, r - cnt, 0);
      change(1, r - cnt + 1, r, 1);
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ask(1, i, i));
}