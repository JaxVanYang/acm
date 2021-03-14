#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 5;

struct node{
    int l, r;
    LL add, sum;
}tr[N * 4];

int w[N];
int n, q;

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void build(int u, int l, int r){
    if (l == r){
        tr[u].l = tr[u].r = l, tr[u].add = 0, tr[u].sum = w[l];
    }else {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
        pushup(u);
    }
}

void pushdown(int u){
    auto &left = tr[u<<1], &right = tr[u<<1|1], &root = tr[u];
    if (root.add){
        left.add += root.add;
        right.add += root.add;
        left.sum += root.add * (LL)(left.r - left.l + 1);
        right.sum += root.add * (LL)(right.r - right.l + 1);
        root.add = 0;
    }
}

void modify(int u, int l, int r, int x){
    if (tr[u].l >= l && tr[u].r <= r){
        tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * x;
        tr[u].add += x;
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u<<1, l, r, x);
        if (r > mid) modify(u<<1|1, l, r, x);
        pushup(u);
    }
}

LL query(int u, int l, int r){
    if (tr[u].l >= l && tr[u].r <= r){
        return tr[u].sum;
    }
    else {
        pushdown(u);
        LL res = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) res += query(u<<1, l, r);
        else if (l > mid) res += query(u<<1|1, l, r);
        else {
            res = query(u<<1, l, r) + query(u<<1|1, l, r);
        }
        return res;
    }
}

int main(){
    
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i ++){
        scanf("%d", &w[i]);
    }
    build(1, 1, n);
    char op[4];
    int i, j;
    while (q --){
        scanf("%s%d%d", op, &i, &j);
        if (*op == 'C'){
            int d;
            scanf("%d", &d);
            modify(1, i, j, d);
        }
        else {
            LL res = query(1, i, j);
            printf("%lld\n", res);
        }
    }
}






