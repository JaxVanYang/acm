// 状态压缩 DP
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 20;
int a[maxn][maxn];
int f[1 << maxn][maxn]; // f[i][j] 表示 i 状态位于 j 的最短路径

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;    // 有效的状态至少有一位是 1
    for (int i = 1; i < 1 << n; ++i)    // 遍历每个状态
        for (int j = 0; j < n; ++j) if (i >> j & 1) // 遍历可选的当前点
            for (int k = 0; k < n; ++k) if ((i ^ 1 << j) >> k & 1) // 遍历可选的上一个点
                f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + a[k][j]);
    cout << f[(1 << n) - 1][n - 1] << endl;
}