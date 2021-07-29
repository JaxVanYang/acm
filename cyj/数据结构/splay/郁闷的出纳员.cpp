/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/952/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-21 23:48:03
 * @LastEditTime: 2021-07-21 23:48:15
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10, INF = 1e9;

struct node {
    int s[2], p, v;
    int size;
    void init(int p1, int v1){
        p = p1, v = v1;
    }
}tr[N];
int res, delta, root, idx, n, m;

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

int insert(int v){
    int u = root, p = 0;
    while (u) p = u, u = tr[u].s[v > tr[u].v];
    u = ++ idx;
    if (p) tr[p].s[v > tr[p].v] = u;
    tr[u].init(p, v);
    splay(u, 0);
    return u;
}

int get(int x){
    int u = root, res;
    while (u){
        if (tr[u].v >= x) res = u, u = tr[u].s[0];
        else u = tr[u].s[1];
    }
    return res;
}

int get_k(int k){
    int u = root;
    while (root){
        if (tr[tr[u].s[0]].size >= k) u = tr[u].s[0];
        else if (tr[tr[u].s[0]].size + 1 == k) return tr[u].v;
        else k -= tr[tr[u].s[0]].size + 1, u = tr[u].s[1];
    }
    return -1;
}

int main(){
    scanf("%d%d", &n, &m);
    int tot = 0;
    int L = insert(-INF), R = insert(INF);
    for (int i = 0; i < n; i ++){
        char s[3];
        int t;
        scanf("%s%d", s, &t);
        if (*s == 'I'){
            if (t >= m) insert(t-delta), tot ++;
        }
        else if (*s == 'A') delta += t;
        else if (*s == 'S'){
            delta -= t;
            int R = get(m-delta);
            splay(R, 0), splay(L, R);
            tr[L].s[1] = 0;
            pushup(L), pushup(R);
        }
        else {
            if (t > tr[root].size - 2) puts("-1");
            else printf("%d\n", get_k(tr[root].size - t) + delta);
        }
    }
    printf("%d\n", tot - tr[root].size + 2);
    return 0;
}