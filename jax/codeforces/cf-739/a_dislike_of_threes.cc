#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

inline bool check(int num) {
	return num % 3 == 0 || num % 10 == 3;
}

void init() {
	int n = 1;
	while (v.size() < 1000) {
		if (!check(n)) v.push_back(n);
		++n;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		cout << v[k - 1] << endl;
	}
}
