/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/949/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-28 12:37:36
 * @LastEditTime: 2021-07-28 12:38:00
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 3 * 1e6 + 100, M = 2 * 1e6 + 100;

struct node {
    int s[2], v, p;
    int size;
    void init(int v1, int p1){
        v = v1, p = p1, size = 1, s[0] = s[1] = 0;
    }
}tr[N];

int nodes[N], tt, n, w[M], root;

void pushup(int u){
    tr[u].size = tr[tr[u].s[0]].size + tr[tr[u].s[1]].size + 1;
}

int build(int p, int l, int r){
    int u = nodes[tt --];
    int mid = l + r >> 1;
    tr[u].init(w[mid], p);
    if (l < mid) tr[u].s[0] =  build(u, l, mid-1); // 注意此处为mid-1
    if (r > mid) tr[u].s[1] =  build(u, mid + 1, r);
    pushup(u);
    return u;
}

void dfs(int u){
    if (tr[u].s[0]) dfs(tr[u].s[0]);
    if (tr[u].s[1]) dfs(tr[u].s[1]);
    nodes[ ++ tt] = u;
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

void output(int u){
    if (tr[u].s[0]) output(tr[u].s[0]);
    if (tr[u].v >= 32 && tr[u].v <= 126) printf("%c", tr[u].v);
    if (tr[u].s[1]) output(tr[u].s[1]);
}

int get_k(int k){
    int u = root;
    while (u){
        if (tr[tr[u].s[0]].size >= k) u = tr[u].s[0];
        else if (tr[tr[u].s[0]].size + 1 == k) return u;
        else k -= tr[tr[u].s[0]].size + 1, u = tr[u].s[1];
    }
    return -1;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i < N; i ++) nodes[++ tt] = i;
    w[0] = -1e9, w[1] = 1e9;
    root = build(0, 0, 1);
    char op[10];
    int len, pos = 1, k;
    while (n --){
        scanf("%s", op);
        if (!strcmp(op, "Insert")){
            scanf("%d", &len);
            int i = 0, k = len;
            while (i < len){
                w[i] = getchar();
                if (w[i] >= 32 && w[i] <= 126) i ++;
            }
            int l = get_k(pos), r = get_k(pos + 1);
            splay(l, 0), splay(r, l);
            tr[r].s[0] = build(r, 0, len-1);
            pushup(r), pushup(l);
        }
        else if (!strcmp(op, "Move")){
            scanf("%d", &k);
            pos = k + 1;
        }
        else if (!strcmp(op, "Delete")){
            scanf("%d", &len);
            int l = get_k(pos), r = get_k(pos + len + 1);
            splay(l, 0), splay(r, l);
            auto &u = tr[r].s[0];
            dfs(u);
            tr[r].s[0] = 0;
            pushup(r), pushup(l);
        }
        else if (!strcmp(op, "Get")){
            scanf("%d", &len);
            int l = get_k(pos), r = get_k(pos + len + 1);
            splay(l, 0), splay(r, l);
            output(tr[r].s[0]);
            puts("");
        }
        else if (!strcmp(op, "Prev")){
            pos --;
        }
        else if (!strcmp(op, "Next")) pos ++;
    }
    return 0;
}