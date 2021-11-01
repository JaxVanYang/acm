/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-08-02 21:18:13
 * @LastEditTime: 2021-08-06 21:05:41
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <limits.h>

using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10;

struct node {
    int l, r;
    int v, add;
}tr[32 * N * 2];
int n, w, h, idx = 1;
struct point{
    int x, y1, y2, l;
    bool operator< (const point & m) {
        return x < m.x;
    }
}q[N * 2];

void pushup(int u){
    tr[u].v = max(tr[tr[u].l].v, tr[tr[u].r].v);
}

void pushdown(int u){
    if (tr[u].add){
        int tmp = tr[u].add;
        tr[u].add = 0;
        tr[tr[u].l].add += tmp, tr[tr[u].r].add += tmp;
        tr[tr[u].l].v += tmp, tr[tr[u].r].v += tmp;
    }
}

void change(int u, int l, int r, int a, int b, int x){
    if (l >= a && r <= b){
        tr[u].v += x;
        tr[u].add += x;
        return;
    }
    int mid = l + r >> 1;
    if (!tr[u].l){
        tr[u].l = ++ idx, tr[u].r = ++ idx;
    }
    pushdown(u);
    if (a <= mid) change(tr[u].l, l, mid, a, b, x);
    if (b > mid) change(tr[u].r, mid + 1, r, a, b, x);
    pushup(u);
}

int main(){
    int T;
    scanf("%d", &T);
    while (T --){
        scanf("%d%d%d", &n, &w, &h);
        for (int i = 1; i <= idx; i ++) {
            tr[i].l = tr[i].r = tr[i].v = tr[i].add = 0;
        }
        idx = 1;
        for (int i = 1; i <= n; i ++){
            int x, y, l;
            scanf("%d%d%d", &x, &y, &l);
            q[i * 2 - 1] = {x, y, min(y + h - 1, INT_MAX), l};
            q[i * 2] = {x + w, y, min(y + h - 1, INT_MAX), -l};
        }
        sort(q+ 1, q + 1 + 2*n);
        int res = 0;
        for (int i = 1; i <= 2 * n; i ++){
            int x = q[i].x, y1 = q[i].y1, y2 = q[i].y2, l = q[i].l;
            // cout << x << ' ' << y1 << ' ' << y2 << ' ' << l << endl;
            // cout << "tmpv " << tr[1].v << endl;
            change(1, 1, INT_MAX, y1, y2, l);
            if (x != q[i+1].x) res = max(res, tr[1].v);
        }
        printf("%d\n", res);
    }
    
    return 0;
}