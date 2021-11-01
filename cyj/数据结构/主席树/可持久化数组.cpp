/*
 * @Descripttion: 

 * @Topic link: https://www.luogu.com.cn/problem/P3919
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-18 09:43:37
 * @LastEditTime: 2021-08-18 09:45:03
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;

int n, m, root[N], idx, w[N];
struct node {
    int l, r, v;
}tr[N * 4 + N * 17];

int build(int l, int r){
    int q = ++ idx;
    if (l == r) {
        tr[q].v = w[l];
        return q;
    }
    int mid = l + r >> 1;
    tr[q].l = build(l, mid);
    tr[q].r = build(mid + 1, r);
    return q;
}

int update(int p, int l, int r, int pos, int x){
    int q = ++ idx;
    if (l == r){
        w[l] = x;
        tr[q].v = x;
        return q;
    }
    tr[q] = tr[p];
    int mid = l + r >> 1;
    if (pos <= mid) tr[q].l = update(tr[p].l, l ,mid, pos, x);
    else tr[q].r = update(tr[p].r, mid + 1, r, pos, x);
    return q;
}

int query(int q, int l, int r, int x){
    if (l == r) return tr[q].v;
    int mid = l +r >> 1;
    if (x <= mid) return query(tr[q].l, l, mid, x);
    else return query(tr[q].r, mid + 1, r, x);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    root[0] = build(1, n);
    for (int i = 1; i <= m; i ++){
        int a, b, c, d;
        scanf("%d%d%d", &a, &b, &c);
        if (b == 1) {
            scanf("%d", &d);
            root[i] = update(root[a], 1, n, c, d);
        }else {
            root[i] = root[a];
            printf("%d\n", query(root[i], 1, n, c));
        }
        
    }
    return 0;
}