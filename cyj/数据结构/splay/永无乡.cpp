/*
 * @Descripttion: 
  splay的启发式合并 合并时间复杂度(n*log^2n)
 * @Topic link: https://www.acwing.com/problem/content/description/1065/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-22 10:30:35
 * @LastEditTime: 2021-07-22 10:31:32
 */

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 5e5 + 10;

struct node {
    int s[2], p, id, v;
    int size;
    void init(int v1, int p1, int id1){
        v = v1, p = p1, id = id1;
    }
}tr[N];
int root[N], idx;
int n, m, q, p[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void pushup(int u){
    tr[u].size = tr[tr[u].s[0]].size + tr[tr[u].s[1]].size + 1;
}

void rotate(int x){
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k^1], tr[tr[x].s[k^1]].p = y;
    tr[x].s[k^1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}

void splay(int x, int k, int b){
    while (tr[x].p != k){
        int y = tr[x].p, z = tr[y].p;
        if (z != k){
            if (tr[z].s[1] == y ^ tr[y].s[1] == x) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if (!k) root[b] = x;
}

void insert(int v, int id, int b){
    int u = root[b], p = 0;
    while (u) p = u, u = tr[u].s[v > tr[u].v];
    u = ++ idx;
    if (p) tr[p].s[v > tr[p].v] = u;
    tr[u].init(v, p, id);
    splay(u, 0, b);
}

void dfs(int u, int b){
    if (tr[u].s[0]) dfs(tr[u].s[0], b);
    if (tr[u].s[1]) dfs(tr[u].s[1], b);
    insert(tr[u].v, tr[u].id, b);
}

int get_k(int k, int b){
    int u = root[b];
    while (u){
        if (tr[tr[u].s[0]].size >= k) u = tr[u].s[0];
        else if (tr[tr[u].s[0]].size + 1 == k) return tr[u].id;
        else k -= tr[tr[u].s[0]].size + 1, u = tr[u].s[1];
    }
    return -1;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++){
        int t;
        scanf("%d", &t);
        root[i] = p[i] = i;
        tr[i].init(t, 0, i);
    }
    idx = n;
    for (int i = 0; i < m; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        a = find(a), b = find(b);
        if (a != b){
            if (tr[root[a]].size > tr[root[b]].size) swap(a, b);
            dfs(root[a], b);
            p[a] = b;
        }
    }
    scanf("%d", &q);
    while (q --){
        char o[2];
        int x, k;
        scanf("%s%d%d", o, &x, &k);
        if (*o == 'B'){
            int a = find(x), b = find(k);
            if (a != b){
                if (tr[root[a]].size > tr[root[b]].size) swap(a, b);
                dfs(root[a], b);
                p[a] = b;
            }
        }
        else {
            int a = find(x);
            printf("%d\n", get_k(k, a));
        }
    }
    
    return 0;
}
