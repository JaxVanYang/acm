#include <iostream>
#include <cstring>
#include <algorithm>

using ll = long long;

const int N = 5e4 + 10, mod = 998244353;
int a[N], b[N], fac[N], invs[N], cnt[N];
int n, m, len;

inline void discrete() {
	memcpy(b, a, sizeof(int) * n);
	std::sort(b, b + n);
	len = std::unique(b, b + n) - b;
}

ll quick(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b & 1) ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}

inline ll inv(ll x) {
	return quick(x, mod - 2);
}

inline ll compose(ll n, ll m) {
	return (ll)fac[n] * invs[m] % mod * invs[n - m] % mod;
}

void init() {
	fac[0] = invs[0] = 1;
	for (int i = 1; i <= std::max(n, m); ++i) {
		fac[i] = (ll)fac[i - 1] * i % mod;
		invs[i] = inv(fac[i]);
		// std::cout << "i = " << i << " fac = " << fac[i] << " invs = " << invs[i] << std::endl;
	}

	discrete();

	for (int i = 0; i < n; ++i) {
		++cnt[std::lower_bound(b, b + len, a[i]) - b];
	}
	// std::cout << "len = " << len << std::endl;
}

int main() {
	scanf("%d%d", &n, &m);

	int max_a = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		max_a = std::max(max_a, a[i]);
	}
	init();

	int lmt = std::min(max_a - 1, m);
	for (int i = 1; i <= lmt; ++i) {
		puts("0");
	}

	for (int i = lmt + 1; i <= m; ++i) {
		ll ans = 1;
		for (int j = 0; j < len; ++j) {
			// std::cout << "ans = " << ans << std::endl;
			// std::cout << "m = " << i << " a[i] = " << b[j] << " c = " << compose(i, b[j]) << std::endl;
			// std::cout << "cnt = " << cnt[j] << std::endl;
			ans = ans * quick(compose(i, b[j]), cnt[j]) % mod;
		}
		printf("%lld\n", ans);
	}
}
