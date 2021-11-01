/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/description/2177/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-09 13:55:10
 * @LastEditTime: 2021-08-09 13:55:18
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 5300, INF = 1e8;

int h[N], e[M], ne[M], f[M], idx;
int n, m, S, T;
int cur[N], d[N], q[N];

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

int main(){
    memset(h, -1, sizeof h);
    cin >> m >> n;
    S = 0, T = n + 1;
    for (int i = 1; i <= m; i ++) add(0, i, 1);
    for (int i = m + 1; i <= n; i ++) add(i, n+1, 1);
    int a, b;
    while (cin >> a >> b, a != -1){
        add(a, b, 1);
    }
    printf("%d\n", dinic());
    for (int i = 0; i < idx; i += 2){
        if (e[i^1] && e[i] != n + 1 && !f[i]) cout << e[i^1] << ' ' << e[i] << endl;
    }
    return 0;
}