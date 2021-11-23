#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 1e5 + 10, K = 105;
const double eps = 1e-4;
int n, k, q;
double a[N], cpy[N], sum[N], ans[K];

void init() {
	memcpy(cpy, a, sizeof(a[0]) * n);
	std::sort(cpy, cpy + n);
	for (int i = n - 1; i >= 0; --i) {
		sum[i] = cpy[i] + sum[i + 1];
	}

	double CNT = (double)n * (n - 1) / 2;

	for (int i = 0; i < n - 1; ++i) {
		ans[0] += (n - i - 1) * cpy[i] + sum[i + 1];
	}
	ans[0] /= CNT;

	for (int t = 1; t <= k; ++t) {
		int p = n;
		for (int i = 0; i < n - 1; ++i) {
			while (p > i && cpy[p - 1] + cpy[i] > ans[t - 1]) --p;

			if (p <= i) {
				ans[t] += (n - i - 1) * cpy[i] + sum[i + 1];
			} else {
				ans[t] += (p - i - 1) * ans[t - 1] + (n - p) * cpy[i] + sum[p];
			}
		}
		ans[t] /= CNT;
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", a + i);
	}

	init();
	printf("%lf\n", ans[k]);

	while (q--) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		if (c == 0) {
			puts("accept");
			continue;
		}

		double val = a[x - 1] + a[y - 1];
		if (std::abs(val - ans[c - 1]) < eps) {
			puts("both");
		} else if (val > ans[c - 1]) {
			puts("accept");
		} else {
			puts("reselect");
		}
	}
}