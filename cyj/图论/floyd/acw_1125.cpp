/*
 * @Descripttion: 牛的旅行
 * @Topic link: https://www.acwing.com/problem/content/1127/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-26 21:25:04
 * @LastEditTime: 2021-03-26 21:53:09
 */


#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define x first
#define y second

using namespace std;

const int N = 155, INF = 1e20;
typedef pair<int, int> PII;
PII p[N];
char g[N][N];
int n;
double dist[N][N], maxd[N], maxv; // 距离矩阵，每个点与其连通块中距离最远的点的距离，最大连通块直径


double get(PII a, PII b){
    int x = a.x - b.x, y = a.y - b.y;
    return sqrt(x * x + y * y);
}

int main(){
    cin >> n;
    for (int i = 0; i < n;  i++) cin >> p[i].x >> p[i].y;
    for (int i = 0; i < n; i ++) cin >> g[i];
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            if (i == j) dist[i][j] = 0;
            else {
                if (g[i][j] == '1') dist[i][j] = get(p[i], p[j]);
                else dist[i][j] = INF;
            }
        }
    }
    
    // floyd求出各点之间的最短距离 
    for (int k = 0; k < n; k ++){
        for (int i = 0; i < n;  i++){
            for (int j = 0; j < n; j ++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    // 求每个点所在连通块中与他距离最远的点的距离，同时求出连通块直径的最大值
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            if (dist[i][j] < INF){
                maxd[i] = max(maxd[i], dist[i][j]);
            }
        }
        maxv = max(maxv, maxd[i]);
    }
    double res = INF;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            if (dist[i][j] >= INF){
                // 此处为取min
                res =  min(res, get(p[i], p[j]) + maxd[i] + maxd[j]);
                // 每个可能的新直径为两点之间的距离加上其连通块中距他最远的点的距离之和
            }
        }
    }
    
    res = max(res, maxv);
    printf("%lf\n", res);
    
    return 0;
}