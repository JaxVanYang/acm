#include <iostream>

const int N = 1e6 + 10;
int d[N];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		++d[u], ++d[v];
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (d[i] > 3) {
			puts("0");
			return 0;
		}
		if (d[i] <= 2) {
			++ans;
		}
	}

	printf("%d\n", ans);

	return 0;
}
