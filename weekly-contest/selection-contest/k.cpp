/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-14 09:18:38
 * @LastEditTime: 2021-03-14 09:18:38
 */

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std; 

const int N = 1e5 + 10;
typedef long long LL;
struct node {
    int l, r;
    LL sum;
}tr[N * 4];

int n, q;
int w[N];

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void build(int u, int l, int r){
    if (l == r){
        tr[u] = {l, l};
        if (l % 2) tr[u].sum  = w[l];
        else tr[u].sum = -w[l];
    }
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int v){
    if (x == tr[u].l && tr[u].r == x){
        if (x % 2) tr[u].sum = v;
        else tr[u].sum = -v;
    }else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u<<1, x, v);
        if (x > mid) modify(u<<1|1, x, v);
        pushup(u);
    }
}

LL query(int u, int l ,int r){
    if (tr[u].l >= l && tr[u].r <= r){
        return tr[u].sum;
    }
    else {
        LL res = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) res += query(u<<1, l, r);
        if (r > mid) res += query(u<<1|1, l, r);
        return res;
    }
}

int main(){
    
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    build(1, 1, n);
    // for (int i = 1; i <= n * 4;  i++) cout << tr[i].sum << " ";
    // cout << endl;
    for (int i = 0; i < q; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1){
            printf("%lld\n", (b % 2) ? query(1, b, c) : -query(1, b, c));
        }else{
            modify(1, b, c);
        }
        
    }
    
    return 0;
}
