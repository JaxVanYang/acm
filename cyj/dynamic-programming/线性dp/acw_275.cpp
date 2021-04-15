/*
 * @Descripttion: 传纸条
 * @Topic link: https://www.acwing.com/problem/content/277/
 * @Question meaning: 
 * 最初容易想到用四元组（x1, y1, x2, y2）两点走到的状态表示状态，但由于每个点只能取一次，
 * 这样的做法需要记录路径，不可行。
 * 想到只有当二者走的步数相同时才有可能相遇，且y1此时可以有x1与步数导出
 * 以（i, x1, x2）为状态，每次可以同时往右走或者同时往下走，或一右一下，
 * 同时判断二者是否在同一点（一同向右或向下）或是否会到达同一点（一右一下），若会则点值只加一次
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-12 20:37:55
 * @LastEditTime: 2021-04-12 20:49:45
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 52;

int f[N * 2][N][N];
int g[N][N];
int n, m;


int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> g[i][j];
        }
    }
    for (int i = 2; i < m + n; i ++){
        for (int j = 1; j <= n && j < i; j ++){
            for (int k = 1; k <= n && k < i; k ++){
                if (j != k){
                    f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k] + g[j][i-j+1] + g[k][i-k+1]);
                    f[i + 1][j+1][k+1] = max(f[i + 1][j+1][k+1], f[i][j][k] + g[j+1][i-j] + g[k+1][i-k]);
                }
                else {
                    f[i+1][j][k] = max(f[i+1][j][k], f[i][j][k] + g[j][i-j+1]);
                    f[i+1][j+1][k+1] = max(f[i+1][j+1][k+1], f[i][j][k] + g[j+1][i-j]);
                }
                if (k + 1 == j) f[i+1][j][k+1] = max(f[i+1][j][k+1], f[i][j][k] + g[k+1][i-k]);
                else f[i+1][j][k+1] = max(f[i+1][j][k+1], f[i][j][k] + g[j][i-j+1] + g[k+1][i-k]);
                if (j + 1 == k) f[i+1][j+1][k] = max(f[i+1][j+1][k], f[i][j][k] + g[k][i-k+1]);
                else f[i+1][j+1][k] = max(f[i+1][j+1][k], f[i][j][k] + g[j+1][i-j] + g[k][i-k+1]);
            }
        }
    }
    cout << f[n+m][n][n];
    return 0;
}