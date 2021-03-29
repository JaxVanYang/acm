/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-14 11:29:04
 * @LastEditTime: 2021-03-15 17:53:02
 */

#include <iostream>
#include <cstdio>
#include <cstdio>

using namespace std;

const int N = 5e4 + 5;

int n, m;
struct node{
    int l, r;
    int sum;
    int st = - 1;
}t[N*4];

int w[N];

void pushup(int u){
    t[u].sum = t[u<<1].sum + t[u<<1|1].sum;
}

void pushdown(int u){
    node &root = t[u], &left = t[u<<1], &right = t[u<<1|1];
    if (root.st != -1){
        left.st = right.st = root.st;
        left.sum = (left.r - left.l + 1) * root.st;
        right.sum = (right.r - right.l + 1) * root.st;
        root.st = -1;
    }
}

void build(int u, int l, int r){
    t[u].st = -1;
    if (l == r){
        t[u] = {l, l};
        t[u].sum = w[l];
    }
    else {
        t[u].l = l, t[u].r = r;
        int mid = l + r >> 1;
        build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int v){
    if (t[u].l >= l && t[u].r <= r){
        // cout << "u " << u << " sum[u] " << t[u].sum << endl;
        t[u].sum = (t[u].r - t[u].l + 1) * v;
        t[u].st = v;
    } else {
        pushdown(u);
        int mid = t[u].l + t[u].r >> 1;
        if (l <= mid) modify(u<<1, l, r, v);
        if (r > mid) modify(u<<1|1, l, r, v);
        pushup(u);
    }
}

int query(int u, int l, int r){
    if (t[u].l >= l && t[u].r <= r){
        // cout << "u " << u << " ";
        // cout << t[u].sum << endl;
        return t[u].sum;
    }
    else {
        pushdown(u);
        int res = 0;
        int mid = t[u].l + t[u].r >> 1;
        // cout << "u " << u << " l " << l << " r " << r << " mid " << mid <<  endl;
        if (l <= mid) res += query(u<<1, l, r);
        if (r > mid) res += query(u<<1|1, l, r);
        // cout << res << endl;
        return res;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    build(1, 1, n);
    // cout << endl;
    // cout << query(1, 1, n) << endl;
    for (int i = 0; i < m ; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int num = query(1, b, c);
        // cout << "num " << num << endl;
        if (a){
            modify(1, b, b + num - 1, 1), modify(1, b + num, c, 0);
        }else {
            modify(1, b, c - num, 0), modify(1, c - num + 1, c, 1);
        }
        // cout << "Case " << i + 1 << " sum[7] "<< t[7].sum << endl;
    }
    // cout << query(1, 5, 5) << endl;
    for (int i = 1; i <= n; i ++) printf("%d ", query(1, i, i));
    // cout << endl;
    // for (int i = 1; i <= 4 * n; i ++){
    //     cout << "sum " << t[i].sum << " st " << t[i].st << endl;
    // }
    
    return 0;
}