#include <iostream>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const int mod = 998244353;
int a[N];
int p[N];

int quick(ll x, ll y) {
	ll ret = 1;
	// x %= mod;

	while (y) {
		if (y & 1) {
			ret = ret * x % mod;
		}

		y >>= 1;

		x = x * x % mod;
	}

	return ret;
}

inline int inv(int n) {
	return quick(n, mod - 2);
}

void init() {
	ll t = 1;

	p[0] = 1;
	for (int i = 1; i < N; ++i) {
		t = t * i % mod;
		p[i] = t;
	}
}

void solve() {
	int n;
	cin >> n;

	int x = -1, y = -1, c = 0, d = 0;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];

		x = max(x, a[i]);
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] == x) ++c;
		else y = max(y, a[i]);
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] == y) ++d;
	}

	// cout << x << " : " << c << ", " << y << " : " << d << endl;

	if (c > 1) {
		cout << p[n] << endl;
	} else if (x - y > 1) {
		cout << 0 << endl;
	} else {
		int rem = n - c - d;
		int m = c + d;

		// ll ans = p[rem] * p[d] % mod * d % mod;

		ll ans = (ll)p[rem] * p[d] % mod;

		ans = ans * d % mod;
		ans = ans * p[n] % mod;
		ans = ans * inv(p[n - m]) % mod;
		ans = ans * inv(p[m]) % mod;

		// cout << "ans = " << ans << endl;

		// ans = ans * p[n] % mod * inv(p[n - m]) % mod * inv(p[m]) % mod;

		cout << ans << endl;
	}
}

int main() {
	int t;
	cin >> t;

	init();

	while (t--) {
		solve();
	}
}
