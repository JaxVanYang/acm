/*
 * @Descripttion: 回忆证明
 * @Topic link: https://www.acwing.com/problem/content/2191/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-11 11:24:05
 * @LastEditTime: 2021-09-13 18:06:34
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 300, M = (N + 10000) * 2, INF = 1e8;

int n, m, S, T;
int f[M], e[M], h[N], ne[M], idx;
int q[N], cur[N], d[N], A[N];

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx ++;
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
        cur[x] = i;
        int j = e[i];
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
    int s, t;
    memset(h, -1, sizeof h);
    scanf("%d%d%d%d", &n, &m, &s, &t);
    S = 0, T = n + 1;
    for (int i = 0; i < m; i ++){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add(a, b, d-c);
        A[a] -= c, A[b] += c;
    }
    int tot = 0;
    for (int i = 1; i <= n; i ++){
        if (A[i] > 0) add(S, i, A[i]), tot += A[i];
        else add(i, T, -A[i]);
    }
    add(t, s, INF);
    if (dinic() < tot) puts("No Solu tion");
    else {
        int res = f[idx - 1]; // s到t的流量等于t到s的流量，等于残余网络上s到t的流量
        S = s, T = t;
        f[idx-1] = f[idx-2] = 0;
        printf("%d\n", res + dinic());
    }
    return 0;
}