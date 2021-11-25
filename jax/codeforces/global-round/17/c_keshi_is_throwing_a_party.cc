#include <iostream>

const int N = 2e5 + 10;
int a[N], b[N];
int n;

bool check(int x) {
	int p = 0;

	for (int i = 0; i < x; ++i) {
		while (p < n && !(x - 1 - a[p] <= i && i <= b[p])) ++p;
		if (p == n) return false;
		++p;
	}

	return true;
}

void solve() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d%d", a + i, b + i);
	}

	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}

	printf("%d\n", l);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		solve();
	}
}
