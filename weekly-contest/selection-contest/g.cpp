/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-14 19:53:05
 * @LastEditTime: 2021-03-14 19:53:14
 */

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 12, M = 1 << N, mod = 1e9 + 7;

int dp[N][M];
int g[N][N];

int T, n, m;

bool valid(int row, int status){
    for (int i = 0; i < m; i ++){
        if ((status >> i & 1) && !g[row][i]) return false;
    }
    int pre = false;
    while (status){
        if (pre && (status & 1)) return false;
        pre = status & 1;
        status >>= 1;
    }
    
    return true;
    
}

int main(){
    
    scanf("%d", &T);
    while (T --){
        memset(dp, 0, sizeof dp);
        
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                scanf("%d", &g[i][j]);
            }
        }
        
        for (int i = 0; i < 1 << m; i ++){
            if (valid(0, i)) dp[0][i] = 1;
            else dp[0][i] = 0;
        }
        
        for (int i = 1; i < n; i ++){
            for (int j = 0; j < 1 << m; j ++){
                dp[i][j] = 0;
                if (valid(i, j)){
                    for (int k = 0; k < 1 << m; k ++){
                        if ((j & k) == 0){
                            dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
                        }
                    }
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < 1 << m; i ++) res = (res % mod + dp[n-1][i] % mod) % mod;
        printf("%d\n", res);
    }
    
    return 0;
}