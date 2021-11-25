#include <iostream>
#include <cmath>
using ll = long long;

const int N = 1e5 + 10, M = 400;
ll a[N], add[M], sum[M], block;

void update(int l, int r, int d) {
	int begin = (l + block - 1) / block;
	int end = r / block;
	for (int i = l; i < (l + block - 1) / block * block; ++i) {
		a[i] += d;
	}
	for (int i = begin; i < end; ++i) {
		add[i] += d;
		sum[i] += (ll)d * block;
	}

	for (int i = end * block; i < r; ++i) {
		a[i] += d;
	}
}

ll ask(int l, int r) {
	ll ret = 0;
	int begin = (l + block - 1) / block;
	int end = r / block;
	for (int i = l; i < (l + block - 1) / block * block; ++i) {
		ret += a[i];
	}
	for (int i = begin; i < end; ++i) {
		ret += sum[i];
	}

	for (int i = end * block; i < r; ++i) {
		ret += a[i];
	}
	return ret;
}

void solve() {
	char s[2];
	int l, r, d;
	scanf("%d%d", &l, &r);

	if (*s == 'C') {
		scanf("%d", &d);

		update(l - 1, r, d);
	} else {
		printf("%lld", ask(l - 1, r));
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	block = sqrt(m);

	for (int i = 0; i < n; ++i) {
		scanf("%lld", a + i);
	}

	while (m--) {
		solve();
	}
}
