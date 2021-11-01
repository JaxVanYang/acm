/*
 * @Descripttion: 
    当我们不想将某一个被割划分到另一部分时，可令S到此点容量为INF/此点到T点容量为INF，当最小割划分割时，
    由S沿残余网络上大于0的边必能走到此点，所以可让此点必属于S的集合，反正则必属于T集合
 * @Topic link: https://www.acwing.com/problem/content/2282/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-17 15:32:45
 * @LastEditTime: 2021-08-17 15:36:53
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
const int N = 510, M = (3000 + N) * 2, INF = 1e8;
int n, m, S, T;
int h[N], e[M], ne[M], f[M], idx;
int cur[N], d[N], q[N], p[N];

struct edge{
    int a, b;
}edges[M];

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx ++;
    e[idx] = a, ne[idx] = h[b], f[idx] = c, h[b] = idx ++;
}

void build(int k){
    memset(h, -1, sizeof h);
    idx = 0;
    for (int i = 0; i < m; i ++){
        int a = edges[i].a, b = edges[i].b;
        add(a, b, 1);
    }
    for (int i = 1; i <= n; i ++){
        if (p[i]){
            if (p[i] >> k & 1) add(i, T, INF);
            else add(S, i, INF);
        }
    }
}

bool bfs(){
    int hh= 0, tt = 0;
    memset(d, -1, sizeof d);
    d[S] = 0, cur[S] = h[S], q[0] = S;
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (d[j] == -1 && f[i]){
                d[j] = d[t] + 1;
                cur[j] = h[j];
                if (j == T) return true;
                q[++ tt]  =j;
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
            int t = find(j, min(limit -flow, f[i]));
            if (!t) d[j] = -1;
            else {
                f[i] -= t, f[i^1] += t, flow += t;
            }
        }
    }
    return flow;
}

int dinic(int k){
    build(k);
    int res = 0, flow;
    while (bfs()){
        while (flow = find(S, INF)) res += flow;
    }
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    S = 0, T = n + 1;
    for (int i = 0; i < m; i ++){
        scanf("%d%d", &edges[i].a, &edges[i].b);
    }
    int k;
    scanf("%d", &k);
    while (k --){
        int a, b;
        scanf("%d%d", &a, &b);
        p[a] = b;
    }
    ll res = 0;
    for (int i = 0; i <= 30; i ++) res += (ll)dinic(i) << i;
    printf("%lld\n", res);
    return 0;
}