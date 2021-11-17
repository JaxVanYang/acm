#include <iostream>
#include <algorithm>
using ll = long long;

const int N = 1e4 + 10, CNT = N << 1, LMT = CNT << 2;
int n, w, h, ys[CNT], size;
ll light[LMT], add[LMT];

inline int get_id(int y) {
	return std::lower_bound(ys, ys + size, y) - ys;
}

struct Node {
	int x, y1, y2, c;
	inline bool operator <(const Node &rhs) const {
		return x < rhs.x || (x == rhs.x && c > rhs.c);
	}
} nodes[CNT];

inline int avg(int x, int y) {
	return (x + y) >> 1;
}

void build(int s = 0, int t = size - 1, int p = 1) {
	light[p] = add[p] = 0ll;
	if (s == t) {
		return;
	}
	int mid = avg(s, t);
	build(s, mid, p << 1);
	build(mid + 1, t, p << 1 | 1);
}

inline void pushdown(int p, int lson, int rson) {
	if (add[p]) {
		ll tmp = add[p];
		add[p] = 0;
		light[lson] += tmp, light[rson] += tmp;
		add[lson] += tmp, add[rson] += tmp;
	}
}
inline void pushup(int p, int lson, int rson) {
	light[p] = std::max(light[lson], light[rson]);
}

void update(int l, int r, int c, int s = 0, int t = size - 1, int p = 1) {
	// std::cout << "s = " << s << " t = " << t << std::endl;
	if (l <= s && t <= r) {
		light[p] += c;
		add[p] += c;
		return;
	}

	int mid = avg(s, t);
	int lson = p << 1, rson = lson | 1;
	pushdown(p, lson, rson);
	if (l <= mid) update(l, r, c, s, mid, lson);
	if (mid < r) update(l, r, c, mid + 1, t, rson);
	pushup(p, lson, rson);
}

ll query(int l = 0, int r = size - 1, int s = 0, int t = size - 1, int p = 1) {
	if (l <= s && t <= r) {
		return light[p];
	}

	int mid = avg(s, t);
	int lson = p << 1, rson = lson | 1;
	pushdown(p, lson, rson);
	ll ret = 0;
	if (l <= mid) ret = query(l, r, s, mid, lson);
	if (mid < r) ret = std::max(ret, query(l, r, mid + 1, t, rson));
	return ret;
}

void solve() {
	for (int i = 0; i < n; ++i) {
		int p1 = i << 1, p2 = p1 | 1;
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);

		int x_ = x - w + 1, y_ = y - h + 1;
		nodes[p1] = {x_, y_, y, c};
		nodes[p2] = {x, y_, y, -c};
		ys[p1] = y_, ys[p2] = y;
	}

	std::sort(ys, ys + n * 2);
	size = std::unique(ys, ys + n * 2) - ys;
	// std::cout << "size = " << size << std::endl;
	build();

	std::sort(nodes, nodes + n * 2);

	ll ans = 0ll;

	for (int i = 0; i < n * 2; ++i) {
		int l = get_id(nodes[i].y1), r = get_id(nodes[i].y2), c = nodes[i].c;
		// std::cout << "l = " << l << " r = " << r << " c = " << c << std::endl;
		update(l, r, c);

		ans = std::max(ans, query());
	}

	printf("%lld\n", ans);
}

int main() {
	while (~scanf("%d%d%d", &n, &w, &h)) {
		solve();
	}
}
