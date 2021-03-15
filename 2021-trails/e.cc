#include <iostream>
using namespace std;

const int maxn = 5e4 + 5;

int n, m;
struct Tree {
  int l, r;
  int cnt;
  int mark = -1;
} t[maxn * 4];

int a[maxn];

void pushup(int u) { t[u].cnt = t[u << 1].cnt + t[u << 1 | 1].cnt; }

void pushdown(int u) {
  if (t[u].mark == -1) return;
  Tree &root = t[u], &left = t[u << 1], &right = t[u << 1 | 1];
  left.mark = right.mark = root.mark;
  left.cnt = (left.r - left.l + 1) * root.mark;
  right.cnt = (right.r - right.l + 1) * root.mark;
  root.mark = -1;
}

void build(int u, int l, int r) {
  //   t[u].mark = -1;
  t[u].l = l, t[u].r = r;
  if (l == r) {
    t[u].cnt = a[l];
  } else {
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
  }
}

void modify(int u, int l, int r, int v) {
  if (l <= t[u].l && t[u].r <= r) {
    t[u].cnt = (t[u].r - t[u].l + 1) * v;
    t[u].mark = v;
  } else {
    pushdown(u);
    int mid = t[u].l + t[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, v);
    if (r > mid) modify(u << 1 | 1, l, r, v);
    pushup(u);
  }
}

int query(int u, int l, int r) {
  if (t[u].l >= l && t[u].r <= r) {
    return t[u].cnt;
  } else {
    pushdown(u);
    int res = 0;
    int mid = t[u].l + t[u].r >> 1;
    if (l <= mid) res += query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);
    return res;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, 1, n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int num = query(1, b, c);
    if (a) {
      modify(1, b, b + num - 1, 1), modify(1, b + num, c, 0);
    } else {
      modify(1, b, c - num, 0), modify(1, c - num + 1, c, 1);
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", query(1, i, i));

  return 0;
}