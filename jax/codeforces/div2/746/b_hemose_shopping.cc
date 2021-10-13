#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];

void solve() {
	int n, x;
	scanf("%d%d", &n, &x);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}

	bool sorted = true;

	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i + 1]) {
			sorted = false;
			break;
		}
	}

	if (sorted) {
		puts("YES");
		return;
	}

	bool mid_sorted = true;

	int l = max(1, n - x + 1), r = min(n, x);
	//cout << "l = " << l << " r = " << r << endl;

	for (int i = l; i < r; ++i) {
		if (a[i] > a[i + 1]) {
			mid_sorted = false;
			break;
		}
	}

	if (!mid_sorted) {
		puts("NO");
		return;
	}

	if (l > r) {
		puts("YES");
		return;
	}

	int c1 = 0, c2 = 0;

	for (int i = 1; i < l; ++i) {
		if (a[i] <= a[l]) {
			++c1;
		}

		if (a[i] >= a[r]) {
			++c2;
		}
	}

	for (int i = r + 1; i <= n; ++i) {
		if (a[i] <= a[l]) {
			++c1;
		}

		if (a[i] >= a[r]) {
			++c2;
		}
	}

	if (c1 >= l - 1 && c2 >= n - r) {
		puts("YES");
	} else {
		puts("NO");
	}
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		solve();
	}
}
