#include <iostream>
using namespace std;

const int N = 105;
int a[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		a[num]++;
	}
	int pair_cnt = 0;
	for (int i = 0; i < N; ++i) {
		pair_cnt += a[i] / 2;
	}
	cout << pair_cnt / 2 << endl;
}
