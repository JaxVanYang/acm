#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int f[1 << 20][20];
int main() {
    memset(f, 0x3f, sizeof(f));
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    f[1][0] = 0;
    for (int i = 1; i < 1 << n; ++i)    // 遍历每个状态
        for (int j = 0; j < n; ++j) if (i >> j & 1) // 选择可选的当前点
            for (int k = 0; k < n; ++k) if ((i ^ 1 << i) >> k & 1)  // 选择上一点
                f[i][j] = min(f[i][j], f[i ^ 1 << j][k] + g[k][j]); // 更新当前点的最短路
    cout << f[(1 << n) - 1][n - 1] << endl;
}