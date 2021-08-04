/*
 * @Descripttion: 
    树上莫队，将树上问题通过某种序列转换为区间问题
 * @Topic link: https://www.acwing.com/problem/content/description/2536/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-30 14:51:45
 * @LastEditTime: 2021-07-30 14:53:59
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 100000;
int h[N], e[N], ne[N], idx;
int depth[N], f[N][17];
int seq[N], top, first[N], last[N];
int cnt[N], ans[N]; // cnt表示此权值出现几次
bool st[N]; // 此节点出现了一次还是两次

struct query{
    int id, l, r, p;
}q[N];
int n, m, w[N], len;
vector<int> nums;

void add_edge(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa){
    seq[++ top] = u;
    first[u] = top;
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (j == fa) continue;
        dfs(j, u);
    }
    seq[++ top] = u;
    last[u] = top;
}

void bfs(){
    int q[N], hh = 0, tt = 0;
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1;
    q[0] = 1;
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (j == t) continue;
            if (depth[j] > depth[t] + 1){
                depth[j] = depth[t] + 1;
                f[j][0] = t;
                for (int k = 1; k <= 16; k ++){
                    f[j][k] = f[f[j][k-1]][k-1];
                }
                q[++ tt] = j;
            }
        }
    }
}

int lca(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = 16; i >= 0; i --){
        if (depth[f[a][i]] >= depth[b]){
            a = f[a][i];
        }
    }
    if (a == b) return a;
    for (int i = 16; i >= 0; i --){
        if (f[a][i] != f[b][i]){
            a = f[a][i], b = f[b][i];
        }
    }
    return f[a][0];
}

int get(int x){
    return (x-1) / len;
}

bool cmp(const query& a, const query& b){
    int i = get(a.l), j = get(b.l);
    if (i != j) return i < j;
    return a.r < b.r;
}

void change(int x, int & res){
    st[x] ^= 1;
    if (st[x]){
        if (!cnt[w[x]]) res ++;
        cnt[w[x]] ++;
    }
    else {
        cnt[w[x]] --;
        if (!cnt[w[x]]) res --;
    }
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]), nums.push_back(w[i]);
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (int i = 1; i <= n; i ++) {
        w[i] = lower_bound(nums.begin(), nums.end(), w[i]) - nums.begin();
    }
    for (int i = 0; i < n - 1; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        add_edge(a, b), add_edge(b, a);
    }
    dfs(1, -1);
    bfs();
    for (int i = 0; i < m; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        if (first[a] > first[b]) swap(a, b);
        int p = lca(a, b);
        if (p == a) q[i] = {i, first[a], first[b]};
        else q[i] = {i, last[a], first[b], first[p]};
    }
    len = sqrt(top);
    sort(q, q + m, cmp);
    for (int i = 1, j = 0, k = 0, res = 0; k < m; k ++){
        int l = q[k].l, r = q[k].r, p = q[k].p, id = q[k].id;
        while (j < r) change(seq[++ j], res);
        while (j > r) change(seq[j --], res);
        while (i > l) change(seq[-- i], res);
        while (i < l) change(seq[i ++], res);
        if (p) change(seq[p], res);
        ans[id] = res;
        if (p) change(seq[p], res);
    }
    for (int i = 0; i < m; i ++) printf("%d\n", ans[i]);
    return 0;
}