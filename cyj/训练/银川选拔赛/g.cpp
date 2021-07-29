/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-28 12:34:33
 * @LastEditTime: 2021-04-28 19:24:17
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e4 + 5, M = 52;

int f[N][101][M];
int n, k;
int a[N];

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int maxv = 0;
    for (int i = 1; i <= n; i ++) cin >> a[i], maxv = max(maxv, a[i]);
    memset(f, 0xcf, sizeof f);
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = 0; j <= maxv; j ++){
            int t = gcd(a[i], j);
            for (int u = 1; u <= k; u ++){
                f[i][t][u] = max(f[i][t][u], f[i-1][j][u]);
                f[i][a[i]][u] = max(f[i][a[i]][u], f[i-1][j][u-1] + j);
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= maxv; i ++){
        res = max(res, f[n][i][k] + i);
    }
    cout << res << endl;
    return 0;
}