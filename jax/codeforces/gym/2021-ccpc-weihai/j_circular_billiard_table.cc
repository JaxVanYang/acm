#include <iostream>
#include <algorithm>

using ll = long long;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		
		ll gcd = std::__gcd(a, 180 * b);
		ll ans = 180 * b / gcd;
		printf("%lld\n", ans - 1);
	}
}
