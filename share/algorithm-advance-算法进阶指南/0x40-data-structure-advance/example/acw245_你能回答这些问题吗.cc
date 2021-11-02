#include <iostream>
using ll = long long;

const int N = 5e5 + 10, M = N << 2;
int a[N], n, m;
ll sum[M], max[M], lmax[M], rmax[M];

constexpr const ll &Max(const ll &x, const ll &y, const ll &z) {
	return std::max(x, std::max(y, z));
}

inline int avg(const int &x, const int &y) {
	return (x + y) >> 1;
}
inline void pushup(const int &p, const int &lson, const int &rson) {
	sum[p] = sum[lson] + sum[rson];
	lmax[p] = std::max(lmax[lson], sum[lson] + lmax[rson]);
	rmax[p] = std::max(rmax[rson], sum[rson] + rmax[lson]);
	max[p] = Max(max[lson], max[rson], rmax[lson] + lmax[rson]);
}

void build(int s = 1, int t = n, int p = 1) {
	if (s == t) {
		sum[p] = max[p] = lmax[p] = rmax[p] = a[s];
		return;
	}
	int mid = avg(s, t);
	int lson = p << 1, rson = lson | 1;
	build(s, mid, lson);
	build(mid + 1, t, rson);
	pushup(p, lson, rson);
}

ll getSum(int l, int r, int s, int t, int p) {
	if (l <= s && t <= r) {
		return sum[p];
	}
	int mid = avg(s, t);
	int lson = p << 1, rson = lson | 1;
	ll ret = 0;
	if (l <= mid) ret += getSum(l, r, s, mid, lson);
	if (mid < r) ret += getSum(l, r, mid + 1, t, rson);
	return ret;
}

ll getLmax(int l, int r, int s = 1, int t = n, int p = 1) {
	if (l <= s && t <= r) {
		return lmax[p];
	}
	int mid = avg(s, t);
	int lson = p << 1, rson = lson | 1;
	ll ret = getLmax(l, r, s, mid, lson);
	if (mid < r) ret = std::max(ret, getSum(l, r, s, mid, lson) + getLmax(l, r, mid + 1, t, rson));
	return ret;
}


ll getRmax(int l, int r, int s = 1, int t = n, int p = 1) {
	if (l <= s && t <= r) {
		return rmax[p];
	}
	int mid = avg(s, t);
	int lson = p << 1, rson = lson | 1;
	ll ret = getRmax(l, r, mid + 1, t, rson);
	if (l <= mid) ret = std::max(ret, getSum(l, r, mid + 1, t, rson) + getRmax(l, r, s, mid, lson));
	return ret;
}

ll getMax(int l, int r, int s = 1, int t = n, int p = 1) {
	if (l <= s && t <= r) {
		return max[p];
	}
	int mid = avg(s, t);
	int lson = p << 1, rson = lson | 1;
	ll ret = INT64_MIN;
	if (l <= mid && mid < r) ret = getRmax(l, r, s, mid, lson) + getLmax(l, r, mid + 1, t, rson);
	if (l <= mid) ret = std::max(ret, getMax(l, r, s, mid, lson));
	if (mid < r) ret = std::max(ret, getMax(l, r, mid + 1, t, rson));
	return ret;
}

void update(int x, int y, int s = 1, int t = n, int p = 1) {
	// std::cout << "s = " << s << " t = " << t << std::endl;
	if (s == t) {
		sum[p] = max[p] = lmax[p] = rmax[p] = y;
		return;
	}
	int mid = avg(s, t);
	int lson = p << 1, rson = lson | 1;
	// std::cout << "mid = " << mid << " lson = " << lson << " rson = " << rson << std::endl;
	if (x <= mid) update(x, y, s, mid, lson);
	else update(x, y, mid + 1, t, rson);
	pushup(p, lson, rson);
}

void solve() {
	int op, x, y;
	scanf("%d%d%d", &op, &x, &y);
	// std::cout << "op = " << op << " x = " << x << " y = " << y << std::endl;
	if (op == 1) {
		if (x > y) std::swap(x, y);
		printf("%lld\n", getMax(x, y));
	} else {
		update(x, y);
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
