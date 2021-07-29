/*
 * @Descripttion: I-country
 * @Topic link: https://www.acwing.com/problem/content/278/
 * @Question meaning: 
 * 求一个具有点权的N*M网格中包含k个格子的凸连通块的权值最大值
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-15 10:53:23
 * @LastEditTime: 2021-04-18 15:17:32
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 17;
int w[N][N], a[N][N];
int f[N][N * N][N][N][2][2];
int n, m, K;

struct pre{
    int i, j, l, r, x, y;
}pres[N][N * N][N][N][2][2];

int main(){

    cin >> n >> m >> K;
    for (int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> w[i][j];
            a[i][j] = a[i][j-1] + w[i][j];
        }
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 0; j <= K; j ++){
            for (int l = 1; l <= m; l ++){
                for (int r = l; r <= m; r ++){
                    if (j < (r - l + 1)) continue;
                    
                    { // 左扩张右扩张
                        auto &v = f[i][j][l][r][1][0];
                        auto &pr = pres[i][j][l][r][1][0];
                        for (int p = l; p <= r; p ++){
                            for (int q = p; q <= r; q ++){
                                if (v < f[i-1][j-(r-l+1)][p][q][1][0]){
                                    v = f[i-1][j-(r-l+1)][p][q][1][0];
                                    pr = {i-1, j-(r-l+1), p, q, 1, 0};
                                }
                            }
                        }
                        v += a[i][r] - a[i][l-1];
                    }

                    { // 左扩张右收缩
                        auto &v = f[i][j][l][r][1][1];
                        auto &pr = pres[i][j][l][r][1][1];
                        for (int p = l; p <= r; p ++){
                            for (int q = r; q <= m; q ++){
                                for(int y = 0; y <= 1; y ++){
                                    if (v < f[i-1][j-(r-l+1)][p][q][1][y]){
                                        v = f[i-1][j-(r-l+1)][p][q][1][y];
                                        pr = {i-1, j-(r-l+1), p, q, 1, y};
                                    }
                                }
                            }
                        }
                        v += a[i][r] - a[i][l-1];
                    }

                    { // 左收缩右扩张
                        auto &v = f[i][j][l][r][0][0];
                        auto &pr = pres[i][j][l][r][0][0];
                        for (int p = 1; p <= l; p ++){
                            for (int q = l; q <= r; q ++){
                                for(int x = 0; x <= 1; x ++){
                                    if (v < f[i-1][j-(r-l+1)][p][q][x][0]){
                                        v = f[i-1][j-(r-l+1)][p][q][x][0];
                                        pr = {i-1, j-(r-l+1), p, q, x, 0};
                                    }
                                }
                            }
                        }
                        v += a[i][r] - a[i][l-1];
                    }

                    { // 左右均收缩
                        auto &v = f[i][j][l][r][0][1];
                        auto &pr = pres[i][j][l][r][0][1];
                        for (int p = 1; p <= l; p ++){
                            for (int q = r; q <= m; q ++){
                                for(int x = 0; x <= 1; x ++){
                                    for (int y = 0; y <= 1; y ++){
                                        if (v < f[i-1][j-(r-l+1)][p][q][x][y]){
                                            v = f[i-1][j-(r-l+1)][p][q][x][y];
                                            pr = {i-1, j-(r-l+1), p, q, x, y};
                                        }
                                    }
                                }
                            }
                        }
                        v += a[i][r] - a[i][l-1];
                    }
                }
            }
        }
    }
    int ans = 0;
    pre tmp;
    for (int i = 1; i <= n; i ++){
        for (int l = 1; l <= m; l ++){
            for (int r = l; r <= m; r ++){
                for(int x = 0; x <= 1; x ++){
                    for (int y = 0; y <= 1; y ++){
                        int v = f[i][K][l][r][x][y];
                        if (v > ans){
                            ans = v;
                            tmp = {i, K, l, r, x, y};
                        }
                    }
                }
            }
        }
    }
    cout << "Oil : " << ans << endl;
    while (tmp.j){
        for (int i = tmp.l; i <= tmp.r; i ++) cout << tmp.i << ' ' << i << endl;
        tmp = pres[tmp.i][tmp.j][tmp.l][tmp.r][tmp.x][tmp.y];
    }

    return 0;
}