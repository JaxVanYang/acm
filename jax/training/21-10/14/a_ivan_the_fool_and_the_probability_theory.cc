#include <iostream>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int f[N];

inline int add(int a, int b) {
	return (a + b) % mod;
}

inline int sub(int a, int b) {
	return (a + mod - b) % mod;
}

void init(int n) {
	f[0] = f[1] = 1;

	for (int i = 2; i <= n; ++i) {
		f[i] = add(f[i - 1], f[i - 2]);
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	if (n < m) {
		swap(n, m);
	}

	init(n);

	int ans = sub(add(f[n], f[m]), 1);
	ans = add(ans, ans);

	printf("%d\n", ans);
}
