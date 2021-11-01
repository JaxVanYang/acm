/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/2192/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-08-16 13:02:54
 * @LastEditTime: 2021-08-16 13:03:07
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 5e4 + 10, M = (N + 125003) * 2, INF = 2147483647;
int n, m, S ,T;
int h[N], e[M], ne[M], f[M], idx;
int cur[N], d[N], q[N], A[N];

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx ++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx ++;
}

bool bfs(){
    memset(d, -1, sizeof d);
    d[S] = 0, cur[S] = h[S];
    int hh = 0, tt = 0;
    q[0] = S;
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (d[j] == -1 && f[i]){
                d[j] = d[t] + 1;
                cur[j] = h[j];
                if (j == T) return true;
                q[++ tt] = j; 
            }
        }
    }
    return false;
}

int find(int x, int limit){
    if (x == T) return limit;
    int flow = 0;
    for (int i = cur[x]; ~i && flow < limit; i = ne[i]){
        int j = e[i];
        cur[x] = i;
        if (d[j] == d[x] + 1 && f[i]){
            int t = find(j, min(limit - flow, f[i]));
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
    int s, t;
    memset(h, -1, sizeof h);
    scanf("%d%d%d%d", &n, &m, &s, &t);
    S = 0, T = n + 1;
    for (int i = 0; i < m; i ++){
        int a, b, c , d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add(a, b, d-c);
        A[b] += c, A[a] -= c;
    }
    int tot = 0;
    for (int i = 1; i <= n; i ++){
        if (A[i] > 0) tot += A[i], add(S, i, A[i]);
        else add(i, T, -A[i]);
    }
    add(t, s, INF);
    if (dinic() < tot) puts("No Solution");
    else {
        int res = f[idx-1];
        f[idx-1] = f[idx-2] = 0;
        S = t, T = s;
        printf("%d\n", res - dinic());
    }
    return 0;
}