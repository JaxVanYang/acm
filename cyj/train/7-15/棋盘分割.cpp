/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-15 11:17:49
 * @LastEditTime: 2021-07-15 11:17:49
 */

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 10, M = 16;
const double INF = 1e9;
int n;
int g[N][N], s[N][N];
double f[N][N][N][N][M], x;

double get(int x1, int y1, int x2, int y2){
    double sum = s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1] - x;
    return sum * sum / n;
}

double dp(int x1, int y1, int x2, int y2, int k){
    double &v = f[x1][y1][x2][y2][k];
    if (v >= 0) return v;
    if (k == 1) return get(x1, y1, x2, y2);
    
    v = INF;
    for (int i = x1; i < x2; i ++){
        v = min(v, dp(x1, y1, i, y2, k-1) + get(i + 1, y1, x2, y2));
        v = min(v, dp(i + 1, y1, x2, y2, k-1) + get(x1, y1, i, y2));
    }
    for (int i = y1; i < y2; i ++){
        v = min(v, dp(x1, y1, x2, i, k-1) + get(x1, i + 1, x2, y2));
        v = min(v, dp(x1, i + 1, x2, y2, k-1) + get(x1, y1, x2, i));
    }
    return v;
}

int main(){
    cin >> n;
    for (int i = 1; i <= 8; i ++){
        for (int j = 1; j <= 8; j ++){
            cin >> g[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + g[i][j];
        }
    }
    memset(f, -1, sizeof f);
    x = (double)s[8][8] / n;
    printf("%.3lf\n", sqrt(dp(1, 1, 8, 8, n)));
    
    return 0;
}