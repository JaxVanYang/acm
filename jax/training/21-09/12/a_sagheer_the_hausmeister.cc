#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> building(n);

	for (int i = 0; i < n; ++i) {
		cin >> building[i];
	}

	vector<vector<int>> dp(n, vector<int>(2, 1e7));

	int last = n;

	for (int i = 0; i < n; ++i) {
		if (building[i].find('1') != string::npos) {
			last = i;
			break;
		}
	}

	if (last == n) {
		cout << 0 << endl;
		return 0;
	}

	if (building[n - 1].find('1') != string::npos) {
		int r = building[n - 1].rfind('1');
		dp[n - 1][0] = 2 * r;
	} else {
		dp[n - 1][0] = 0;
	}
	dp[n - 1][1] = m + 1;

	for (int i = n - 2; i > last; --i) {
		if (building[i].find('1') == string::npos) {
			dp[i][0] = min(dp[i + 1][0] + 1, dp[i + 1][1] + m + 2);
			dp[i][1] = min(dp[i + 1][1] + 1, dp[i + 1][0] + m + 2);
		} else {
			int l = building[i].find('1');
			int r = building[i].rfind('1');
			// cout << "l = " << l << " r = " << r << endl;

			dp[i][0] = min(dp[i + 1][0] + 1 + 2 * r, dp[i + 1][1] + m + 2);
			dp[i][1] = min(dp[i + 1][1] + 1 + 2 * (m + 1 - l), dp[i + 1][0] + m + 2);
		}
	}

	for (int i = 0; i < n; ++i) {
		// cout << "dp[" << i << "]: " << dp[i][0] << ' ' << dp[i][1] << endl;
	}


	int l = building[last].find('1');
	int r = building[last].rfind('1');

	if (last == n - 1) {
		cout << r << endl;
		return 0;
	}

	cout << min(dp[last + 1][0] + r, dp[last + 1][1] + m + 1 - l) + 1 << endl;
}

