#include <bits/stdc++.h>
using namespace std;

const int N = 16;
const int ALL = (1 << N) - 1;
const int DEP = N * N + 1;
char grid[N][N + 1], gCpy[DEP][N][N + 1];
int mark[N][N], mCpy[DEP][N][N], mTmp[DEP][N][N];
int ones[1 << N], h[1 << N];

inline int lowbit(int n) {
	return n & -n;
}
inline int count(int n) {
	int ret = 0;
	for (; n; ++ret, n -= lowbit(n));
	return ret;
}

inline void record(char gCpy[N][N + 1], int mCpy[N][N]) {
	memcpy(gCpy, grid, sizeof grid);
	memcpy(mCpy, mark, sizeof mark);
}
inline void back(char gCpy[N][N + 1], int mCpy[N][N]) {
	memcpy(grid, gCpy, sizeof grid);
	memcpy(mark, mCpy, sizeof mark);
}

void draw(int row, int col, int bit) {
	grid[row][col] = bit + 'A';
	int mask = ~(1 << bit);
	for (int i = 0; i < N; ++i) {
		mark[row][i] &= mask;
		mark[i][col] &= mask;
	}
	int r = row / 4 * 4, c = col / 4 * 4;
	for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) mark[r + i][c + j] &= mask;
	mark[row][col] = 1 << bit;
}

int prework() {
	int ret = 0;

	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) mark[i][j] = ALL;

	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) if (grid[i][j] == '-') ++ret;
	else draw(i, j, grid[i][j] - 'A');

	return ret;
}

bool dfs(int left) {
	// cout << "left = " << left << endl;
	if (!left) return true;

	const int dep = left;
	record(gCpy[dep], mCpy[dep]);
	auto bak = [&]() { back(gCpy[dep], mCpy[dep]); };
	// auto dra = [&](int row, int col, int bit) {
	// 	draw(row, col, bit);
	// };

	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) if (grid[i][j] == '-') {
		if (ones[mark[i][j]] == 0) {
			bak();
			return false;
		}
		if (ones[mark[i][j]] == 1) {
			draw(i, j, h[mark[i][j]]);
			--left;
		}
	}

	for (int r = 0; r < N; r += 4) for (int c = 0; c < N; c += 4) {
		int sor = 0, sand = ALL, drawn = 0;
		for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) {
			int s = mark[r + i][c + j];
			sand &= ~(sor & s);
			sor |= s;
			if (grid[r + i][c + j] != '-') drawn |= s;
		}

		if (sor != ALL) {
			bak();
			return false;
		}

		for (int mask = sand; mask;) {
			int low = lowbit(mask);

			if (!(low & drawn)) {
				for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) {
					int x = r + i, y = c + j;
					if (low & mark[x][y]) {
						draw(x, y, h[low]);
						--left;
						break;
					}
				}
			}

			mask -= low;
		}
	}

	for (int i = 0; i < N; ++i) {
		int sor = 0, sand = ALL, drawn = 0;
		for (int j = 0; j < N; ++j) {
			int s = mark[i][j];
			sand &= ~(sor & s);
			sor |= s;
			if (grid[i][j] != '-') drawn |= s;
		}

		if (sor != ALL) {
			bak();
			return false;
		}

		for (int mask = sand; mask;) {
			int low = lowbit(mask);

			if (!(low & drawn)) {
				for (int j = 0; j < N; ++j) {
					if (low & mark[i][j]) {
						draw(i, j, h[low]);
						--left;
						break;
					}
				}
			}

			mask -= low;
		}
	}

	for (int j = 0; j < N; ++j) {
		int sor = 0, sand = ALL, drawn = 0;
		for (int i = 0; i < N; ++i) {
			int s = mark[i][j];
			sand &= ~(sor & s);
			sor |= s;
			if (grid[i][j] != '-') drawn |= s;
		}

		if (sor != ALL) {
			bak();
			return false;
		}

		for (int mask = sand; mask;) {
			int low = lowbit(mask);

			if (!(low & drawn)) {
				for (int i = 0; i < N; ++i) {
					if (low & mark[i][j]) {
						draw(i, j, h[low]);
						--left;
						break;
					}
				}
			}

			mask -= low;
		}
	}
	if (!left) return true;

	int r = -1, c = -1, val = INT32_MAX;
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) if (grid[i][j] == '-' && ones[mark[i][j]] < val) {
		val = ones[mark[i][j]];
		r = i, c = j;
	}
	assert(r != -1);

	memcpy(mTmp[dep], mark, sizeof mark);
	for (int mask = mark[r][c]; mask;) {
		int low = lowbit(mask);
		
		draw(r, c, h[low]);
		if (dfs(left - 1)) return true;
		memcpy(mark, mTmp[dep], sizeof mark);

		mask -= low;
	}

	bak();
	return false;
}

int main() {
	for (int i = 0; i < N; ++i) h[1 << i] = i;
	for (int i = 0; i < 1 << N; ++i) ones[i] = count(i);

	while (cin >> grid[0]) {
		for (int i = 1; i < N; ++i) cin >> grid[i];

		int tot = prework();
		// cout << "tot = " << tot << endl;
		dfs(tot);
		for (int i = 0; i < N; ++i) cout << grid[i] << endl;
		cout << endl;
	}
}