#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
pair<int, int> ps[N];

void solve() {
	int n;
	cin >> n;

	ll sum = 0;

	for (int i = 1; i <= n; ++i) {
		cin >> ps[i].first;
		ps[i].second = 0;

		sum += ps[i].first;
	}

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;

		++ps[u].second, ++ ps[v].second;
	}

	sort(ps + 1, ps + n + 1, greater<pair<int, int>>());

	cout << sum;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < ps[i].second; ++j) {
			sum += ps[i].first;
			cout << ' ' << sum;
		}
	}

	cout << endl;
}



int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}
