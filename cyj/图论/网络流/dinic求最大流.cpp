/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/description/2174/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-09 11:03:35
 * @LastEditTime: 2021-09-13 12:27:50
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010, M = 200010, INF = 1e8;

int h[N], e[M], f[M], ne[M], idx;
int n, m, S, T;
int d[N], cur[N], q[N];

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx ++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx ++;
}

bool bfs(){
    memset(d, -1, sizeof d);
    int hh = 0, tt = 0;
    d[S] = 0;
    q[0] = S, cur[S] = h[S];
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (d[j] == -1 && f[i]){
                d[j] = d[t] + 1;
                cur[j] = h[j];
                q[ ++ tt] = j;
                if (j == T) return true;
            }
        }
    }
    return false;
}

int find(int u, int limit){
    if (u == T) return limit;
    int flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i]){ // 可行性优化
        int j = e[i];                    
        cur[u] = i; // 当前弧优化
        if (d[j] == d[u] + 1 && f[i]){ 
            int t = find(j, min(limit - flow, f[i]));
            if (!t) d[j] = -1; // 费点优化
            else {
                f[i] -= t, f[i^1] += t, flow += t;
            }
        }
    }
    return flow;
}

int dinic(){
    int res = 0, flow;
    while (bfs()){
        while (flow = find(S, INF)) res += flow;
    }
    return res;
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d%d%d", &n, &m, &S, &T);
    for (int i = 0; i < m; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    printf("%d\n", dinic());
    return 0;
}