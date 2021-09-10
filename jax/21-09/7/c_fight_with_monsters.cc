#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;

int h[N], cost[N];
int n, a, b, k, c;

int calc(int val) {
	int rem = val % c;

	if (rem == 0) {
		rem = c;
	}

	return (rem - 1) / a;
}


int main() {
	cin >> n >> a >> b >> k;

	c = a + b;

	for (int i = 0; i < n; ++i) {
		cin >> h[i];

		cost[i] = calc(h[i]);
	}

	sort(cost, cost + n);

	int ans = 0;

	for (int i = 0; i < n; ++i) {
		if (cost[i] <= k) {
			++ans;
			k -= cost[i];
		}
	}

	cout << ans << endl;
}
