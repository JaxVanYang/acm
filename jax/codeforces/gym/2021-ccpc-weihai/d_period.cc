#include <iostream>
#include <cstring>
using ull = unsigned long long;

const int N = 1e6 + 10, K = 131;
char s[N];
ull hash[N], p[N];
int sum[N], n;

inline ull Hash(int len) {
	return hash[n] - hash[n - len] * p[len];
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);

	p[0] = 1;
	for (int i = 1; i <= n; ++i) {
		hash[i] = hash[i - 1] * K + s[i] - 'a';
		p[i] = p[i - 1] * K;
	}

	for (int i = 1; i <= n / 2; ++i) {
		if (hash[i] == Hash(i)) sum[i] = 1;
		sum[i] += sum[i - 1];
		// std::cout << "sum[" << i << "] = " << sum[i] << std::endl;
	}

	int q;
	scanf("%d", &q);
	while (q--) {
		int i;
		scanf("%d", &i);

		int lmt = std::min(i - 1, n - i);
		printf("%d\n", sum[lmt]);
	}
}
