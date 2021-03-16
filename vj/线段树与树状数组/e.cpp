/*
 * @Descripttion: 建树时lazy标记与l，r一样每个都需初始化
 * @Author: cyj
 * @Date: 2021-03-11 09:49:14
 * @LastEditTime: 2021-03-11 15:54:00
 */

#include <iostream>
#include <cstring> 
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5;

struct node{
    int l, r;
    int mul, sum;
}tr[N * 4];
int n, m;

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void build(int u, int l, int r){
    if (l == r){
        tr[u].l = tr[u].r = l, tr[u].sum = 1;
    }else {
        tr[u].mul = 0; // 错点每个点的lazy均需初始化为0
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
        pushup(u);
    }
}

void pushdown(int u){
    node &root = tr[u], &left = tr[u<<1], &right = tr[u<<1|1];
    if (root.mul){
        left.mul = root.mul;
        right.mul = root.mul;
        left.sum = (left.r - left.l + 1) * root.mul;
        right.sum = (right.r - right.l + 1) * root.mul;
        root.mul = 0;
    }
}

void modify(int u, int l, int r, int v){
    if (tr[u].l >= l && tr[u].r <= r){
        tr[u].mul = v;
        tr[u].sum = (tr[u].r - tr[u].l + 1) * v;
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u<<1, l, r, v);
        if (r > mid) modify(u<<1|1, l, r, v);
        pushup(u);
    }
}

int query(int u, int l, int r){
    if (tr[u].l >= l && tr[u].r <= r){
        return tr[u].sum;
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int res = 0;
        if (r <= mid) res += query(u<<1, l, r);
        else if (l > mid) res += query(u<<1|1, l, r);
        else {
            res = query(u<<1, l, r) + query(u<<1|1, l, r);
        }
        return res;
    }
}

int main(){
    int T;
    int tim = 1;
    scanf("%d", &T);
    while (T --){
        scanf("%d%d", &n, &m);
        build(1, 1, n);
        for (int i = 0; i < m; i ++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            modify(1, a, b, c);
        }
        
        printf("Case %d: The total value of the hook is %d.\n", tim ++, tr[1].sum);
    }
    
    return 0;
}