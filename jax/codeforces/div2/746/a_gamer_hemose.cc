#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e3 + 10;
int a[N];

void solve() {
	int n, h;
	scanf("%d%d", &n, &h);

	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}

	sort(a, a + n, greater<int>());

	int sum = a[0] + a[1];

	int ans = h / sum * 2;
	if (h % sum > a[0]) {
		ans += 2;
	} else if (h % sum > 0) {
		++ans;
	}

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		solve();
	}
}
