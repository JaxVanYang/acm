/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/description/2238/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-08-16 15:49:25
 * @LastEditTime: 2021-08-16 15:51:36
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 510, M = 10010, INF = 1e8;

int h[N], e[M], ne[M], f[M], idx;
int cur[N], q[N], d[N];
bool vis_s[N], vis_t[N];
int n, m, S, T;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx ++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx ++;
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

void dfs(int u, bool st[], int t){
    st[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (!st[j] && f[i^t]){
            dfs(j, st, t);
        }
    }
}

int find(int x, int limit){
    if (x == T) return limit;
    int flow = 0;
    for (int i = cur[x]; ~i && flow < limit; i = ne[i]){
        int j = e[i];
        cur[x] = i;
        if (d[j] == d[x] + 1 && f[i]){
            int t = find(j, min(limit-flow, f[i]));
            if (!t) d[j] = -1;
            else {
                f[i] -= t, f[i ^1] += t, flow += t;
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
    S = 0, T = n-1;
    for (int i = 0; i < m; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    dinic();
    dfs(S, vis_s, 0);
    dfs(T, vis_t, 1);
    int res = 0;
    for (int i = 0; i < idx; i += 2){
        // 此边应满足流量等于容量，且残余网络上S可以沿容量大于0的边走到该边起点i，可由该边终点j沿容量大于0的边走到T
        if (!f[i] && vis_t[e[i]] && vis_s[e[i^1]]){
            res ++;
        }
    }
    printf("%d\n",res);
    return 0;
}