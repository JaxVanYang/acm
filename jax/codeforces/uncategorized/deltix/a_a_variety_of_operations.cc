#include <iostream>
using namespace std;

void solve() {
	int c, d;
	cin >> c >> d;
	int diff = abs(c - d);

	if (diff & 1) {
		cout << -1 << endl;
		return;
	}

	if (c == d && c == 0) {
		cout << 0 << endl;
	} else if (diff == 0) {
		cout << 1 << endl;
	} else {
		cout << 2 << endl;
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}
