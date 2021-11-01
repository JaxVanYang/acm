/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-10-14 01:09:01
 * @LastEditTime: 2021-10-14 21:43:14
 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 4e5 + 10, M = 2 * N;
int head[N], ver[M], nex[M], tot = 0;
int d[N];

inline void reset(int n) {
	memset(d + 1, 0, sizeof(int) * n);
	memset(head + 1, 0, sizeof(int) * n);
	memset(ver + 1, 0, sizeof(int) * tot);
	memset(nex + 1, 0, sizeof(int) * tot);
	tot = 0;
}

inline void add(int u, int v) {
	ver[++tot] = v;
	nex[tot] = head[u], head[u] = tot;
}

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	reset(n);

	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);

		add(u, v);
		add(v, u);

		++d[u], ++d[v];
	}
	
	queue<int> q;

	for (int i = 1; i <= n; ++i) {
		if (d[i] == 1) {
			q.push(i);
		}
	}

	int ans = n;

	for (int i = 0; i < k; ++i) {
		int size = q.size();

		if (size == 0) {
			ans = 0;
			break;
		}

		for (int j = 0; j < size; ++j) {
			int u = q.front();
			q.pop();

			// cout << "u = " << u << " d = " << d[u] << endl;

			--ans;
			--d[u];

			for (int p = head[u]; p; p = nex[p]) {
				int v = ver[p];

				// cout << "v = " << v << " d = " << d[v] << endl;

				--d[v];

				if (d[v] == 1) {
					q.push(v);
				}
			}
		}
	}

	ans = max(0, ans);

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		solve();
	}
}
