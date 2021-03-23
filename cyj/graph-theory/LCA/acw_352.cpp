/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/354/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-22 20:22:24
 * @LastEditTime: 2021-03-22 20:22:37
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e5  +10, M = N * 2;

int e[M], h[N], ne[M], idx;
int n, m, ans;
int d[N], q[N], f[N][17];
int depth[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u, int fa){
    int res = d[u];
    for (int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if (j != fa){
            int s = dfs(j, u);
            if (s == 0) ans += m;
            else if (s == 1) ans += 1;
            res += s;
        }
    }
    
    return res;
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
                f[j][0] = t;
                for (int k = 1; k <= 16; k ++){
                    f[j][k] = f[f[j][k-1]][k-1];
                }
            }
        }
    }
}

int lca(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 16; k >= 0; k --){
        if (depth[f[a][k]] >= depth[b]){
            a = f[a][k];
        }
    }
    if (a == b) return a;
    for (int k = 16; k >= 0; k --){
        if (f[a][k] != f[b][k]){
            a= f[a][k];
            b= f[b][k];
        }
    }
    return f[a][0];
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    bfs();
    for (int i = 0; i < m; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        d[a] += 1, d[b] += 1;
        d[lca(a, b)] -= 2;
    }
    dfs(1, -1);
    printf("%d", ans);
    
    return 0;
}