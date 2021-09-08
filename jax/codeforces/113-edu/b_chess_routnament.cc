#include <iostream>
using namespace std;

const int N = 55;

char ans[N][N];

void reset(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans[i][j] = i == j ? 'X' : '=';
		}
	}
}

void solve() {
	int n;
	cin >> n;

	reset(n);

	string s;
	cin >> s;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') continue;

		bool flag = false;
		for (int j = 0; j < n; ++j) {
			if (i == j || ans[i][j] != '=' || s[j] == '1') continue;

			ans[i][j] = '+';
			ans[j][i] = '-';
			flag = true;
			break;
		}

		if (!flag) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}
