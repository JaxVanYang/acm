/*
 * @Descripttion: 维护序列
 * @Topic link: https://ac.nowcoder.com/acm/contest/967/D
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-25 12:31:46
 * @LastEditTime: 2021-03-25 12:53:13
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 1e5 + 5;

struct node{
    int l, r;
    int sum, mul, add;
}tr[N * 4];
int w[N];
int n, m, p;

void cal(node &u, int mul, int add){
    u.sum = (((LL)u.sum * mul) % p + add * (LL)(u.r - u.l + 1)) % p;
    u.mul = (LL)u.mul * mul % p;
    u.add = ((LL)u.add * mul + add) % p;
}

void pushdown(int u){
    cal(tr[u<<1], tr[u].mul, tr[u].add);
    cal(tr[u<<1|1], tr[u].mul, tr[u].add);
    tr[u].mul = 1, tr[u].add = 0;
}

void pushup(int u){
    tr[u].sum = (tr[u<<1].sum + tr[u<<1|1].sum) % p;
}

void build(int u, int l, int r){
    if (l == r) tr[u] = {l, l, w[l], 1, 0};
    else {
        tr[u] = {l, r, 0, 1, 0};
        int mid = l + r >> 1;
        build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int mul, int add){
    if (tr[u].l >= l && tr[u].r <= r){
        cal(tr[u], mul, add);
        return;
    }
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u<<1, l, r, mul, add);
        if (r > mid) modify(u<<1|1, l, r, mul, add);
        pushup(u);
    }
}

int query(int u, int l, int r){
    if (tr[u].l >= l && tr[u].r <= r){
        return tr[u].sum;
    }
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int res = 0;
        if (l <= mid) res += query(u<<1, l, r);
        if (r > mid) res =(res +  query(u<<1|1, l, r)) % p;
        return res;
    }
}

int main(){
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i ++){
        scanf("%d", &w[i]);
    }
    build(1, 1, n);
    scanf("%d", &m);
    for (int i = 0; i < m; i ++){
        int op, l, r, c;
        scanf("%d", &op);
        if (op == 3){
            scanf("%d%d", &l, &r);
            printf("%d\n", query(1, l, r));
        }else {
            scanf("%d%d%d", &l, &r, &c);
            if (op == 1) modify(1, l, r, c, 0);
            else modify(1, l, r, 1, c);
        }
        
    }
    
    
    return 0;
}