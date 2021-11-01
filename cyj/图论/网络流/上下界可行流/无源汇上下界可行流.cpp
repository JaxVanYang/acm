/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/2190/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-09 15:36:57
 * @LastEditTime: 2021-08-09 15:37:08
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 210, M = (10200 + N) * 2, INF = 1e8;

int h[N], e[M], ne[M], l[M], f[M], idx;
int n, m, S, T;
int q[N], cur[N], d[N], A[N];

void add(int a, int b, int c, int d){
    e[idx] = b, ne[idx] = h[a], l[idx] = c, f[idx] = d-c, h[a] = idx ++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx ++;
}

bool bfs(){
    int hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    d[S] = 0, q[0] = S, cur[S] = h[S];
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (d[j] == -1 && f[i]){
                d[j] = d[t] + 1;
                cur[j] = h[j];
                if (j == T) return true;
                q[ ++ tt] = j;
            }
        }
    }
    return false;
}

int find(int x, int limit){
    if (x == T) return limit;
    int flow = 0;
    for (int i = cur[x]; ~i && flow < limit; i = ne[i]){
        cur[x] = i;
        int j =e[i];
        if (d[j] == d[x] + 1 && f[i]){
            int t = find(j, min(limit-flow, f[i]));
            if (!t) d[j] = -1;
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
    scanf("%d%d", &n, &m);
    S = 0, T = n + 1;
    int tot = 0;
    for (int i = 0; i < m; i ++){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add(a, b, c, d);
        A[a] -= c, A[b] += c;
    }
    for (int i = 1; i <= n; i ++){
        if (A[i] > 0) add(S, i, 0, A[i]), tot += A[i];
        else add(i, T, 0, -A[i]);
    }
    int res = dinic();
    if (res != tot) puts("NO");
    else {
        puts("YES");
        for (int i = 0; i < 2 * m; i += 2){
            printf("%d\n", f[i^1] + l[i]);
        }
    }
    
    return 0;
}