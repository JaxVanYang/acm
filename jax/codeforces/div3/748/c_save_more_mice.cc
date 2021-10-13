#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 4e5 + 10;
int a[N];

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= k; ++i) {
		scanf("%d", a + i);
	}

	sort(a + 1, a + k + 1, greater<int>());
	
	int ans = 0, pos = 0;
	for (int i = 1; i <= k; ++i) {
		if (pos < a[i]) {
			++ans;
			pos += n - a[i];
		} else {
			break;
		}
	}

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		solve();
	}
}
