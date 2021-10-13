#include <iostream>
#include <string>
using namespace std;
using ll = long long;

void solve() {
	ll n;
	scanf("%lld", &n);

	string s = to_string(n);

	int ans = 100, len = s.size();

	for (int i = 0; i < len; ++i) {
		if (s[i] == '0') {
			for (int j = i - 1; j >= 0; --j) {
				if (s[j] == '0' || s[j] == '5') {
					ans = min(ans, len - 1 - i + i - j - 1);
					break;
				}
			}
		} else if (s[i] == '5') {
			for (int j = i - 1; j >= 0; --j) {
				if (s[j] == '2' || s[j] == '7') {
					ans = min(ans, len - j - 2);
					break;
				}
			}
		}
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
