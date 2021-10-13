#include <iostream>
using namespace std;

const int N = 45;
int a[N];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int *min_element(int *begin, int *end) {
	int *ret = begin;

	while (begin < end) {
		if (*begin < *ret) {
			ret = begin;
		}
		++begin;
	}

	return ret;
}

void solve() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}

	int min_v = *min_element(a, a + n);

	int ans = 0;

	for (int i = 0; i < n; ++i) {
		ans =  gcd(ans, a[i] - min_v);
	}

	if (ans == 0) {
		ans = -1;
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
