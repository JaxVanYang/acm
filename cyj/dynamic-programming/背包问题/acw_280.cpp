/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-16 17:03:03
 * @LastEditTime: 2021-04-16 17:24:34
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 205, M = 22;

int f[M][800];
int p[N], q[N];
int n, m;

int main(){
    while (cin >> n >> m, n && m){
        for (int i = 1; i <= n; i ++) cin >> p[i] >> q[i];

        memset(f, 0xcf, sizeof f);
        f[0][0] = 0;
        for (int i = 1; i <= n; i ++){
            for (int j = m; j ; j --){
                for (int k = -20 * m; k <= 20 * m; k ++){
                    if (k - p[i] - q[i] < -20 * m || k - p[i] - q[i] > 20 * m) continue;
                    f[j][k + 400] = max(f[j][k + 400], f[j-1][k-(p[i]-q[i]) + 400] + p[i] + q[i]);
                }
            }
        }

        int minv = 1<<30, fl = 0;
        for (int k = 0; k <= 800; k ++){
            if (f[m][k] != 0xcfcfcfcf){
                if ()
            }
        }
    }

    return 0;
}