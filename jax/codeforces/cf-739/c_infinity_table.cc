#include <iostream>
using namespace std;
using ll = long long;

void solve() {
	int k;
	cin >> k;
	ll l = 1, r = k;
	while (l < r) {
		ll mid = l + r + 1 >> 1;
		if (mid * mid > k) r = mid - 1;
		else l = mid;
	}
	ll s = l * l;
	int rem = k - s;
	int row, col;
	
	//cout << "l = " << l << endl;
	//cout << "k = " << k << endl;
	//cout << "rem = " << rem << endl;
	if (rem == 0) {
		row = l;
		col = 1;
	} else if (rem <= l + 1) {
		row = rem;
		col = l + 1;
	} else {
		row = l + 1;
		col = l + 1 - (rem - l) + 1;
	}
	cout << row << ' ' << col << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
