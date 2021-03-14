/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-10 19:25:18
 * @LastEditTime: 2021-03-10 19:25:18
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 2e5 + 5;

struct node{
    int l, r;
    int max;
}tr[N * 4];

int n, m;
int w[N];

void pushup(int u){
    tr[u].max = max(tr[u<<1].max, tr[u<<1|1].max);
}

void build(int u, int l, int r){
    if (l == r){
        tr[u] = {l, l, w[l]};
    }else {
        int mid = l + r >> 1;
        tr[u] = {l, r};
        build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int v){
    if (tr[u].l == x && tr[u].r == x){
        tr[u].max = v;
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u<<1, x, v);
        else modify(u<<1|1, x, v);
        pushup(u);
    }
}

int query(int u, int l, int r){
    if (tr[u].l >= l && tr[u].r <= r){
        return tr[u].max;
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u<<1, l, r);
        else if (l > mid) return query(u<<1|1, l, r);
        else {
            int left = query(u<<1, l, r), right = query(u<<1|1, l, r);
            int res=  max(left, right);
            return res;
        }
    }
}

int main(){
    
    while (scanf("%d%d", &n, &m) != EOF){
        for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
        
        build(1, 1, n);
        
        char op[4];
        int x, y;
        for (int i = 0; i < m; i ++){
            scanf("%s%d%d", op, &x, &y);
            if (*op == 'Q'){
                printf("%d\n", query(1, x, y));
            }
            else modify(1, x, y);
        }
    }
    
    
    return 0;
}