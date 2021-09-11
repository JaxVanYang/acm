#include <cstring>
#include <iostream>
#include <map>
using namespace std;

const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int nex[N][26];

void solve() {
	string s, t;
	cin >> s >> t;

	const int n = s.size(), m = t.size();

	memset(nex, 0x3f, sizeof(int) * 26 * (n + 5));

	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 26; ++j) {
			nex[i][j] = nex[i + 1][j];
		}

		nex[i][s[i] - 'a'] = i;
	}

	int ans = 1, pos = 0;

	for (int i = 0; i < m; ++i) {
		if (nex[pos][t[i] - 'a'] == inf) {
			pos = 0;
			++ans;
		}

		if (nex[pos][t[i] - 'a'] == inf) {
			ans = -1;
			break;
		}

		pos = nex[pos][t[i] - 'a'] + 1;
	}

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}
