/*
 * @Descripttion: 花神游历各国 暴力修改
 * @Topic link: https://ac.nowcoder.com/acm/contest/967/D
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-25 12:35:34
 * @LastEditTime: 2021-03-25 16:27:13
 */

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

// 1e9开根号五次后就会变为0或1，暴力修改，tag标记区间是否已全为0或1，即不用修改
using namespace std;

const int N = 1e5 + 5;
typedef long long LL;
int n, m;

struct node {
    int l, r;
    int tag;
    LL sum;
}tr[N * 4];;

int w[N];

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
    tr[u].tag = tr[u<<1].tag & tr[u<<1|1].tag;
}

void pushdown(int u){ // 每次pushdown会将需要修改的地方全部修改完，所以query时已为正确值，
                      // 不需要pushdown
    if (!tr[u].tag){
        if (tr[u].l == tr[u].r){
            tr[u].sum = floor(sqrt(tr[u].sum));
            if (tr[u].sum <= 1) tr[u].tag = 1;
            return;
        }
        pushdown(u<<1), pushdown(u<<1|1);
        pushup(u);
    }
}

void build(int u, int l, int r){
    if (l == r){
        tr[u] = {l, r, 0, w[l]};
    }
    else {
        tr[u] = {l, r, 0, 0};
        int mid = l + r >> 1;
        build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r){
    if (tr[u].tag) return;
    if (tr[u].l >= l && tr[u].r <= r){
        pushdown(u);
        return;
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u<<1, l, r);
        if (r > mid) modify(u<<1|1, l, r);
        pushup(u);
    }
}

LL query(int u, int l, int r){
    if (tr[u].l >= l && tr[u].r <= r){
        return tr[u].sum;
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        LL res = 0;
        if (l <= mid) res += query(u<<1, l, r);
        if (r > mid) res += query(u<<1|1, l, r);
        return res;
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 1;  i<= n; i ++) scanf("%d", &w[i]);
    scanf("%d", &m);
    build(1, 1, n);
    int x, l ,r;
    for (int i = 0;  i< m; i ++){
        scanf("%d%d%d", &x, &l, &r);
        if (x == 1) printf("%lld\n", query(1, l, r));
        else modify(1, l, r);
    }
    
    return 0;
}