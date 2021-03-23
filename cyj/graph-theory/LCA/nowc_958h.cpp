/*
 * @Descripttion: 树上倍增优化求次小生成树
 * @Topic link: https://ac.nowcoder.com/acm/contest/958/H
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-22 17:03:47
 * @LastEditTime: 2021-03-22 17:04:07
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5, M = 3e5 + 5, INF = 0x3f3f3f3f;
typedef long long LL;

int e[M], ne[M], w[M], h[N], idx;
int n, m;
int f[N][17], d1[N][17], d2[N][17];
int p[N], depth[N], q[N];

struct Edge{
    int a, b, c;
    bool used = 0;
    bool operator< (const Edge & m){
        return c < m.c;
    }
}edge[M];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void bfs(){
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1;
    int hh = 0, tt = 0;
    q[0] = 1;
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (depth[j] > depth[t] + 1){
                depth[j] = depth[t] + 1;
                q[++ tt] = j;
                f[j][0] = t, d1[j][0] = w[i], d2[j][0] = -INF;
                for (int k = 1; k <= 16; k ++){
                    int mid = f[j][k-1];
                    f[j][k] = f[mid][k-1];
                    int dis1[4] = {d1[j][k-1], d2[j][k-1], d1[mid][k-1], d2[mid][k-1]};
                    d1[j][k] = d2[j][k] = -INF; // 更改处
                    for (int u = 0; u < 4; u ++){
                        if (dis1[u] > d1[j][k]) d2[j][k] = d1[j][k], d1[j][k] = dis1[u];
                        else if (dis1[u] != d1[j][k] && dis1[u] > d2[j][k]) d2[j][k] = dis1[u];
                    }
                }
                
            }
        }
    }
}

LL kruskal(){
    for (int i = 1; i <= n; i ++) p[i] = i;
    sort(edge, edge + m);
    LL res = 0;
    for (int i = 0; i < m; i ++){
        int pa = find(edge[i].a), pb = find(edge[i].b), c = edge[i].c;
        if (pa != pb){
            p[pa] = pb;
            res += c;
            edge[i].used = true;
        }
    }
    
    return res;
}

int lca(int a, int b, int w){
    static int dis[N * 2];
    int cnt = 0;
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 16; k >= 0; k --){
        if (depth[f[a][k]] >= depth[b]){
            dis[cnt ++] = d1[a][k];
            dis[cnt ++] = d2[a][k];
            a = f[a][k];
        }
    }
    if (a != b){
        for (int k = 16; k >= 0; k --){
            if (f[a][k] != f[b][k]){
                dis[cnt ++] = d1[a][k];
                dis[cnt ++] = d2[a][k];
                dis[cnt ++] = d1[b][k];
                dis[cnt ++] = d2[b][k];
                a = f[a][k];
                b = f[b][k];
            }
        }
        dis[cnt ++] = d1[a][0];
        dis[cnt ++] = d1[b][0];
    }
    int dist1 = -INF, dist2 = -INF;
    for (int i = 0; i < cnt; i ++){
        if (dis[i] > dist1) dist2 = dist1, dist1 = dis[i];
        else if (dis[i] != dist1 && dis[i] > dist2) dist2 = dis[i];
    }
    if (w > dist1) return w - dist1;
    if (w > dist2) return w - dist2;
    else return INF;
}

int main(){
    
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[i] = {a, b, c};
    } 
    
    LL sum = kruskal();
    for (int i = 0; i < m; i ++){
        if (edge[i].used){
            int a = edge[i].a, b = edge[i].b, c = edge[i].c;
            add(a, b, c), add(b, a, c);
        }
    }
    bfs();
    LL ans = 1e18;
    for (int i = 0; i < m; i ++){
        if (!edge[i].used){
            ans = min(ans, sum + lca(edge[i].a, edge[i].b, edge[i].c));
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}