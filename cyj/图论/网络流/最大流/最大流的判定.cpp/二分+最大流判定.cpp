/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/2279/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-17 11:03:25
 * @LastEditTime: 2021-08-17 13:52:24
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 210, M = 4e4 * 4 + 10, INF = 1e8;

int h[N], e[M], ne[M], f[M], idx, w[M];
int n, m, S, T, K;
int q[N], d[N], cur[N];

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
    e[idx] = a, ne[idx] = h[b], w[idx] = c, h[b] = idx ++;
}

bool bfs(){
    int hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    q[0] = S, cur[S] = h[S], d[S] = 0;
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

int check(int x){
    memset(f, 0, sizeof f);
    for (int i = 0; i < idx - 1; i += 2){
        if (w[i] <= x) f[i] = 1, f[i ^ 1] = 1;
    }
    int res = dinic();
    return res;
}

int main(){
    scanf("%d%d%d", &n, &m, &K);
    memset(h, -1, sizeof h);
    S = 1, T = n;
    for (int i = 0; i < m; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        // 无向图，两个方向的边也只能用一次，在流网络中若两条边均使用了等于未使用，所以直接用dinic可求出正确答案
        add(a, b, c);
    }
    int l = 1, r = 1e6;
    while (l < r){
        int mid = l + r >> 1;
        if (check(mid) >= K) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}