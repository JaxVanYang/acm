#include <iostream>
#include <cctype>
using namespace std;

void solve() {
	string p;
	cin >> p;

	int k = p.size() - 1;

	string x;
	cin >> x;

	for (char &ch : x) {
		ch = isdigit(ch) ? ch - '0' : ch - 'A' + 10;
	}

	string num;

	for (char ch : x) {
		for (int i = 3; i >= 0; --i) {
			num += ((ch >> i) & 1) + '0';
		}
	}

	int begin = 0;
	while (num[begin] == '0') {
		++begin;
	}

	for (int i = 0; i < k; ++i) {
		num.push_back('0');
	}

	while (num.size() - begin > k) {
		for (int i = 0; i < p.size(); ++i) {
			num[begin + i] = num[begin + i] == p[i] ? '0' : '1';
		}

		while (num.size() - begin > k && num[begin] == '0') {
			++begin;
		}
	}

	printf("%s\n", num.c_str() + begin);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}
