/*
 * @Descripttion: 
  最短路 + 3进制状压dp
 * @Topic link: https://ac.nowcoder.com/acm/problem/13252
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-17 21:55:35
 * @LastEditTime: 2021-07-17 23:33:33
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 15, M = 1 << 10, P = 22;

int g[P][P];
int p[N], s[N], t[N], l[N], r[N];
int f[60000][P];

int count(int u){
    int res = 0;
    while (u){
        if (u % 3 == 2) res ++;
        u /= 3;
    }
    return res;
}

int main(){
    int n, m, q;
    cin >> n >> m  >> q;
    p[0] = 1;
    memset(g, 0x3f, sizeof g);
    
    for (int i = 1; i <= n;i ++) g[i][i] = 0;
    for (int i = 0; i< m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    for (int i = 0; i < q; i ++){
        cin >> s[i] >> t[i] >> l[i] >> r[i];
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            for (int k = 1; k <= n; k ++){
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }
    for (int i = 1; i <= q; i ++) p[i] = p[i-1] * 3;
    memset(f, 0x3f, sizeof f);
    f[0][1] = 0;
    for (int i = 1; i < p[q]; i ++){
        for (int j = 0; j < q; j ++){
            int x = (i / p[j]) % 3;
            if (x== 1){
                for (int u = 1; u <= n; u ++){
                    if ( f[i-p[j]][u] < 0x3f3f3f3f && f[i-p[j]][u] + g[u][s[j]] <= r[j]){
                    f[i][s[j]] = max(l[j], min(f[i][s[j]], f[i-p[j]][u] + g[u][s[j]]));
                    }
                }
            }
            else if (x == 2){
                for (int u = 1; u <= n; u ++){
                    if (f[i-p[j]][u] < 0x3f3f3f3f && f[i-p[j]][u] + g[u][t[j]] <= r[j]){
                        f[i][t[j]] = min(f[i][t[j]], f[i-p[j]][u] + g[u][t[j]]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < p[q]; i ++){
        for (int j = 1; j <= n; j ++){
            if (f[i][j] < 0x3f3f3f3f) ans = max(ans, count(i));
        }
    }
    cout << ans << endl;
    return 0;
}