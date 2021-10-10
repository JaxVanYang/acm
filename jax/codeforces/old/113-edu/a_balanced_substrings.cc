#include <iostream>
#include <algorithm>
using namespace std;

const int N = 55;

int sum[N];

void solve() {
	int n;
	cin >> n;

	fill(sum + 1, sum + n + 1, 0);

	string s;
	cin >> s;

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'a') {
			sum[i + 1] = sum[i] + 1;
		} else {
			sum[i + 1] = sum[i] - 1;
		}
	}

	for (int l = 1; l < n; ++l) {
		for (int r = l + 1; r <= n; ++r) {
			if (sum[l - 1] == sum[r]) {
				cout << l << ' ' << r << endl;
				return;
			}
		}
	}

	cout << "-1 -1" << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}
