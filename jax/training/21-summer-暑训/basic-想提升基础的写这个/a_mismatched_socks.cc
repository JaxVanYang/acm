#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1005;
int a[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n, [](int a, int b) { return a > b; });
	ll sum = 0;
	for (int i = 1; i < n; ++i) {
		sum += a[i];
	}
	if (sum >= a[0]) {
		/**
		  Assume that x = sum - a[0]
		  then we shoule move x / 2 to a[0] side
		  let's move 
		 */
		sum += a[0];
		sum /= 2;
	}
	cout << sum << endl;
}

