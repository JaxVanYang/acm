/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/957/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-22 22:23:05
 * @LastEditTime: 2021-07-22 22:56:35
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5e5 + 10, INF = 1e9;

struct node {
    int s[2], p, v;
    int size, sum, ms, ls, rs;
    int rev, same;
    void init(int v1, int p1){
        rev = same = s[0] = s[1] = 0;
        v= v1, p = p1, size = 1, sum = ms = v, ls = rs = max(0, v1);
    }
}tr[N];
int root, idx;
int n, m, nodes[N], tt, w[N];

void pushup(int x){
    auto &u = tr[x], &l = tr[tr[x].s[0]], &r = tr[tr[x].s[1]];
    u.size = l.size + r.size + 1;
    u.sum = l.sum + r.sum + u.v;
    u.ms = max(max(l.ms, r.ms), l.rs + u.v + r.ls);
    u.ls = max(l.ls, l.sum + u.v + r.ls);
    u.rs = max(r.rs, r.sum + u.v + l.rs);
}

void pushdown(int x){
    auto &u = tr[x], &l = tr[tr[x].s[0]], &r = tr[tr[x].s[1]];
    if (u.same){
        u.same = u.rev = 0;
        if (u.s[0]) l.same = 1, l.v = u.v, l.sum = l.v * l.size;
        if (u.s[1]) r.same = 1, r.v = u.v, r.sum = r.v * r.size;
        if (u.v > 0){
            if (u.s[0]) l.ms = l.ls = l.rs = l.sum;
            if (u.s[1]) r.ms = r.rs = r.ls = r.sum;
        }
        else {
            if (u.s[0]) l.ms = l.v, l.ls = l.rs = 0;
            if (u.s[1]) r.ms = r.v, r.ls = r.rs = 0;
        }
    }
    else if (u.rev){
        u.rev = 0;
        l.rev ^= 1, r.rev ^= 1;;
        swap(l.ls, l.rs), swap(r.ls, r.rs);
        swap(l.s[0], l.s[1]), swap(r.s[0], r.s[1]);
    }
}

void dfs(int u){
    if (tr[u].s[0]) dfs(tr[u].s[0]);
    if (tr[u].s[1]) dfs(tr[u].s[1]);
    nodes[++ tt] = u;
}

int build(int l, int r, int p){
    int mid = l + r >> 1;
    int u = nodes[tt --];
    tr[u].init(w[mid], p);
    if (l < mid) tr[u].s[0] = build(l, mid - 1, u);
    if (r > mid) tr[u].s[1] = build(mid + 1, r, u);
    pushup(u);
    return u;
}

void rotate(int x){
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k^1], tr[tr[x].s[k^1]].p = y;
    tr[x].s[k^1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}

void splay(int x, int k){
    while (tr[x].p != k){
        int y = tr[x].p, z = tr[y].p;
        if (z != k){
            if (tr[z].s[1] == y ^ tr[y].s[1] == x) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if (!k) root = x;
}

int get_k(int k){
    int p = root;
    while (p){
        pushdown(p);
        if (tr[tr[p].s[0]].size >= k) p = tr[p].s[0];
        else if (tr[tr[p].s[0]].size + 1 == k) return p;
        else k -= tr[tr[p].s[0]].size + 1, p = tr[p].s[1];
    }
    return -1;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i < N; i ++) nodes[++ tt] = i;
    
    // 防止空子树（即0号点）影响属性的更新，将0号点初始化为负无穷
    tr[0].ms = w[0] = w[n+1] = -INF;
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    root = build(0, n + 1, 0);
    char c[20];
    while (m --){
        int pos, tot;
        scanf("%s", c);
        if (!strcmp(c, "INSERT")){
            scanf("%d%d", &pos, &tot);
            for (int i = 0; i < tot; i ++){
                scanf("%d", &w[i]);
            }
            int l = get_k(pos + 1), r = get_k(pos + 2);
            splay(l, 0), splay(r, l);
            int u = build(0, tot-1, r);
            tr[r].s[0] = u;
            pushup(r), pushup(l);
        }
        else if (!strcmp(c, "DELETE")){
            scanf("%d%d", &pos, &tot);
            int l = get_k(pos), r = get_k(pos + tot + 1);
            splay(l, 0), splay(r, l);
            dfs(tr[r].s[0]); 
            tr[r].s[0] = 0;
            pushup(r), pushup(l);
        }
        else if (!strcmp(c, "MAKE-SAME")){
            int v;
            scanf("%d%d%d", &pos, &tot, &v);
            int l = get_k(pos), r = get_k(pos + tot + 1);
            splay(l, 0), splay(r, l);
            auto &t = tr[tr[r].s[0]];
            t.same = 1, t.v = v, t.sum = v * (t.size);
            if (v > 0) t.ms = t.ls = t.rs = t.sum;
            else t.ms = v, t.ls = t.rs = 0;
            pushup(r), pushup(l);
        }
        else if (!strcmp(c, "GET-SUM")){
            scanf("%d%d", &pos, &tot);
            int l = get_k(pos), r = get_k(pos + tot + 1);
            splay(l, 0), splay(r, l);
            printf("%d\n", tr[tr[r].s[0]].sum);
        }
        else if (!strcmp(c, "REVERSE")){
            scanf("%d%d", &pos, &tot);
            int l = get_k(pos), r = get_k(pos + tot + 1);
            splay(l, 0), splay(r, l);
            auto &t = tr[tr[r].s[0]];
            t.rev ^= 1;
            swap(t.ls, t.rs);
            swap(t.s[0], t.s[1]);
            pushup(r), pushup(l);
        }
        else printf("%d\n", tr[root].ms);
    }
    
    return 0;
}
