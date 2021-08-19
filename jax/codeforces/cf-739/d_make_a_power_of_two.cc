#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<string> sv;

void init() {
	ull n = 1;
	for (int i = 0; i < 64; ++i) {
		sv.push_back(to_string(n));
		n <<= 1;
	}
}

int calc(const string &s, const string &t) {
	int ret = 0;
	int len0 = s.size(), len1 = t.size();
	int i = 0, j = 0;
	while (i < len0 && j < len1) {
		//cout << "i = " << i << " j = " << j << endl;
		if (s[i] == t[j]) {
			++i, ++j;
		} else {
			++i, ++ret;
		}
	}
	//cout << "ret = " << ret << endl;
	return ret + len1 - j + len0 - i;
}


void solve() {
	int n;
	cin >> n;
	string s = to_string(n);
	int ans = INT32_MAX;
	for (auto &t : sv) {
		ans = min(ans, calc(s, t));
	}
	cout << ans << endl;
}

int main() {
	init();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
