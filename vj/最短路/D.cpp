/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-05 14:34:36
 * @LastEditTime: 2021-03-05 14:43:20
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 205;
PII p[N];
double  g[N][N];
double dist[N];
bool st[N];
int n;

double get_d(int i, int j){
    return sqrt((double)(p[i].x - p[j].x) * (p[i].x - p[j].x) + (double)(p[i].y - p[j].y) * (p[i].y - p[j].y));
}

void dijkstra(){
    for (int i = 1; i <= n; i ++) dist[i] = 0x3f3f3f3f;
    memset(st, 0, sizeof st);
    dist[1] = 0;
    
    for (int i = 1; i <= n; i ++){
        int t = -1;
        for (int j = 1; j <= n; j ++){
            if (!st[j] && (t == -1 || dist[j] < dist[t])){
                t = j;
            }
        }
        
        st[t] = true;
        for (int j = 1; j <= n ; j ++){
            // dist[j] = min(dist[j], max(dist[t], g[t][j]));
            dist[j] = dist[t] + g[t][j];
        }
    }
}

int main(){
    
    int q = 1;
    while (scanf("%d", &n), n){
        for (int i = 1; i <= n; i ++){
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        
        for (int i = 1; i <= n; i ++){
            for (int j = i + 1; j <= n; j ++){
                g[i][j] = g[j][i] = get_d(i, j);
            }
        }
        
        dijkstra();
        
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", q ++, dist[2]);
    }
    
    return 0;
}