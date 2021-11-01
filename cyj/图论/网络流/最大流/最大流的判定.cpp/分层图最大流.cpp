/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/2189/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-17 10:32:02
 * @LastEditTime: 2021-08-17 10:32:10
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 751 * 14 + 2, M = (750 * 20 + N + 750) * 2, INF = 1e8;
int n, m, K, S, T;
int q[N], cur[N], d[N];
int h[N], e[M], ne[M], f[M], idx;
struct Ship{
    int h, r, id[18];
}ships[25];
int p[30];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int get(int i, int day){
    return day * (n + 2) + i;
}

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx ++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx ++;
}

bool bfs(){
    int hh = 0, tt  = 0;
    memset(d, -1, sizeof d);
    q[0] = S, cur[S] = h[S], d[S] = 0;
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = h[t]; ~i ; i=ne[i]){
            int j  =e[i];
            if (d[j] == -1 && f[i]){
                d[j] = d[t] + 1;
                cur[j] = h[j];
                if(j == T) return true;
                q[ ++ tt]  =j;
            }
        }
    }
    return false;
}

int find(int x, int limit){
    if (x == T) return limit;
    int flow = 0;
    for (int i  =cur[x]; ~i && flow < limit; i = ne[i]){
        cur[x] = i;
        int j  =e[i];
        if (d[j] == d[x] + 1 && f[i]){
            int t = find(j, min(f[i], limit - flow));
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
    scanf("%d%d%d", &n, &m, &K);
    S = 0, T = N - 1;
    for (int i = 0; i <= n + 1; i ++) p[i] = i;
    for (int i = 0; i < m; i ++){
        int h ,r;
        scanf("%d%d", &h, &r);
        ships[i] = {h, r};
        for (int j = 0; j < r; j ++){
            scanf("%d", &h);
            if (h == -1) h = n + 1;
            ships[i].id[j] = h;
            if (j){
                int p1 = find(h), p2 = find(ships[i].id[j-1]);
                if (p1 != p2){
                    p[p2] = p1;
                }
            }
        }
    }
    if (find(0) != find(n+1)) puts("0");
    else {
        add(S, get(0, 0), INF);
        add(get(n+1, 0), T, INF);
        int day = 1, res = 0;
        while (true){
            add(get(n+1, day), T, INF);
            for (int i = 0; i <= n + 1; i ++){
                add(get(i, day-1), get(i, day), INF);
            }
            for (int i = 0; i < m; i ++){
                int r = ships[i].r;
                int a = ships[i].id[(day-1) % r], b = ships[i].id[day % r];
                add(get(a, day-1), get(b, day), ships[i].h);
            }
            res += dinic();
            if (res >= K) break;
            day ++;
        }
        printf("%d\n", day);
    }
    return 0;
}