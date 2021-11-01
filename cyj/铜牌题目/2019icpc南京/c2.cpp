/*
 * @Descripttion: 
 * @Topic link: https://nanti.jisuanke.com/t/42397
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-10-24 21:36:29
 * @LastEditTime: 2021-10-24 22:05:18
 */

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1010, mod = 1e9 + 7;
typedef pair<int, int> PII;
int g[N][N];
int in[N][N], f[N][N][4], out[N][N];
int ans, n, m;
vector<PII> s;
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
PII q[N * N];
void topsort(){
    int hh = 0, tt  = -1;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (!in[i][j]) q[++ tt] = {i, j}, f[i][j][0] = 1;
        }
    }
    while (hh <= tt){
        auto t = q[hh ++];
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; i ++){
            int x1 = x + dx[i], y1 = y + dy[i];
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && g[x1][y1] == g[x][y] + 1){
                f[x1][y1][1] = (f[x1][y1][1] + f[x][y][0]) % mod;
                f[x1][y1][2] = (f[x1][y1][2] + f[x][y][1]) % mod;
                f[x1][y1][3] = (f[x1][y1][3] + f[x][y][2] + (long long)f[x][y][3]) % mod;
                if (-- in[x1][y1] == 0) q[++ tt] = {x1, y1};
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i<= n; i ++){
        for (int j =1; j <= m; j ++){
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j ++){
            for (int k = 0; k < 4; k ++){
                int x = i + dx[k], y = j + dy[k];
                if (x >= 1 && x <= n && y >= 1 && y <= m){
                    if (g[x][y] == g[i][j] + 1) in[x][y] ++, out[i][j] ++;
                }
            }
        }
    }
    topsort();
    for (int i = 1; i<= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (!out[i][j]) ans = (ans + f[i][j][3]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}