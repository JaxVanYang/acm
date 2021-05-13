// 两个数的乘积包含了二者的所有因数
#include <iostream>
#include <algorithm>

using ll = long long;

const int maxn = 15e4 + 5;
int a[maxn], b[maxn];

int main() {
	int n;
	scanf("%d", &n);
	auto gcd = std::__gcd<ll>;
	ll g = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", a + i, b + i);
		g = gcd(g, (ll)a[i] * b[i]);
	}
	if (g == 1) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (gcd(g, a[i]) > 1) {
			g = gcd(g, a[i]);
		} else {
			g = gcd(g, b[i]);
		}
	}
	printf("%lld\n", g);
}