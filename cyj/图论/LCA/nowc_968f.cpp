/*
 * @Descripttion: 
 * @Topic link: https://ac.nowcoder.com/acm/contest/968/F
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-22 11:40:59
 * @LastEditTime: 2021-03-22 11:42:54
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 4e4 + 10, M = 2 * N;

int ne[M], e[M], h[N], w[M], idx;
int n, m;
int f[N][16], depth[N];
int q[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int lca(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 15; k >= 0; k --){
        if (depth[f[a][k]] >= depth[b]){ // 哨兵作用1：当跳出树时depth为0，不满足条件，退出
            a = f[a][k];
        }
    }
    if (a == b) return a;
    for (int k = 15; k >= 0; k --){
        if (f[a][k] != f[b][k]){ // 哨兵作用2：当跳出去时，a，b位于同一层，两者都为0，不满足条件，k继续减
            a = f[a][k];
            b = f[b][k];
        }
    }
    return f[a][0];
}

void bfs(int root){
    int hh = 0, tt = 0;
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;
    q[0] = root;
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (depth[j] > depth[t] + 1){
                depth[j] = depth[t] + 1;
                q[++ tt] = j;
                f[j][0] = t;
                for (int k = 1; k <= 15; k ++){
                    f[j][k] = f[f[j][k-1]][k-1];
                }
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    int root = 0; 
    memset(h, -1, sizeof h);
    for (int i = 0; i < n; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        if (b == -1) root = a;
        add(a, b), add(b, a);
    }
    scanf("%d", &m);
    bfs(root);
    for (int i = 0; i < m; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        int fa = lca(a, b);
        if (fa == a) puts("1");
        else if (fa == b) puts("2");
        else puts("0");
    }
    return 0;
}
