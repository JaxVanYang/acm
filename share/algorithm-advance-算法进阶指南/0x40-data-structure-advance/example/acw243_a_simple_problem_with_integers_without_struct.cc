#include <iostream>
using ll = long long;

const int N = 1e5 + 10, M = N << 2;
int n, m;
int a[N];
ll sum[M], lazy[M];

inline int avg(int a, int b) {
	return (a + b) >> 1;
}

inline void pushup(int p, int lson, int rson) {
	sum[p] = sum[lson] + sum[rson];
}

void build(int s = 1, int t = n, int p = 1) {
    if (s == t) {
		sum[p] = a[s];
		return;
    }

    int mid = avg(s, t);
	int lson = p << 1, rson = lson | 1;
    build(s, mid, lson);
    build(mid + 1, t, rson);
	
	pushup(p, lson, rson);
}

void pushdown(int p, int lson, int rson, ll lc, ll rc) {
	if (lazy[p]) {
		ll tmp = lazy[p];
		lazy[p] = 0;
		sum[lson] += lc * tmp, sum[rson] += rc * tmp;
		lazy[lson] += tmp, lazy[rson] += tmp;
	}
}

void add(int l, int r, int d, int s = 1, int t = n, int p = 1) {
    if (l <= s && t <= r) {
		sum[p] += (t - s + 1ll) * d, lazy[p] += d;
        return;
    }

    int mid = avg(s, t);
	int lson = p << 1, rson = lson | 1;
	pushdown(p, lson, rson, mid - s + 1, t - mid);
	if (l <= mid) add(l, r, d, s, mid, lson);
	if (mid < r) add(l, r, d, mid + 1, t, rson);
	pushup(p, lson, rson);
}

ll ask(int l, int r, int s = 1, int t = n, int p = 1) {
    if (l <= s && t <= r) {
        return sum[p];
    }

    int mid = avg(s, t);
	int lson = p << 1, rson = lson | 1;
	pushdown(p, lson, rson, mid - s + 1, t - mid);

    ll ret = 0;
	if (l <= mid) ret += ask(l, r, s, mid, lson);
	if (mid < r) ret += ask(l, r, mid + 1, t, rson);
    return ret;
}

void solve() {
	char op[2];
	int l, r, d;
	scanf("%s%d%d", op, &l, &r);

	if (*op == 'C') {
		scanf("%d", &d);
		add(l, r, d);
	} else {
		printf("%lld\n", ask(l, r));
	}
}

int main() {
	scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
    }

    build();

	while (m--) {
		solve();
	}
}
