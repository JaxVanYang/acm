#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
		int len = (b - a) * 2;
		if (c > len || a > len || b > len) {
			cout << -1 << endl;
			continue;
		}
		int ans = (c - 1 + len / 2) % len + 1;
		cout << ans << endl;
	}
}
