/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-09 19:37:45
 * @LastEditTime: 2021-03-09 20:40:16
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 105;
const double INF = 1e7, eps = 1e-8;

int T;
double g[N][N];
double dist[N];
bool st[N];

double get_dist(PII a, PII b){
    int x1 = a.x, x2 = b.x, y1 = a.y, y2 = b.y;
    double res = sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1-y2) * (y1-y2));
    if (res >= 10 && res <= 1000) return res;
    else return INF;
}

int n;
PII node[N];

double prim(){
    for (int i = 1; i <= n; i ++) dist[i] = INF;
    memset(st, 0, sizeof st);

    double res = 0;
    for (int i = 0; i < n; i++){
        int t = -1;
        for (int j = 1; j <= n; j ++){
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        }
        
        st[t] = true;
        // cout << dist[t] << endl;
        if (i && dist[t] == INF) return INF;
        if (i) res += dist[t];
        // cout << res << endl;
        for (int j = 1; j <= n; j ++){
            dist[j] = min(dist[j], g[t][j]);
        } 
    }
    
    return res;
}

int main(){

    // ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T --){
        cin >> n;
        for (int i = 0; i <= n; i ++){
            for (int j = 0; j <= n; j ++){
                g[i][j] = INF;
            }
        }
        for (int i = 1; i <= n; i ++){
            scanf("%d%d", &node[i].x, &node[i].y);
        }
        for (int i = 1; i <= n; i ++){
            for (int j = i + 1; j <= n; j ++){
                g[i][j] = g[j][i] = get_dist(node[i], node[j]);
            }
        }

        double res = prim();
        if (res == INF) puts("oh!");
        else  printf("%.1lf\n", res * 100.0);
    }

    return 0;
}