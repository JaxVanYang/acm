/*
 * @Descripttion: 
 给定一个长度为 N 的数列 A，以及 M 条指令，每条指令可能是以下两种之一：

    C l r d，表示把 A[l],A[l+1],…,A[r] 都加上 d。
    Q l r，表示询问数列中第 l∼r 个数的和。
    对于每个询问，输出一个整数表示答案。
 * @Topic link: https://www.acwing.com/problem/content/description/244/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-27 17:04:01
 * @LastEditTime: 2021-07-27 17:04:18
 */

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 100100;

typedef long long LL;

struct Node{
    int l, r;
    LL sum, add;
}tr[N * 4];
int w[N];

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void build(int u, int l, int r){
    if (l == r){
        tr[u] = {l, l, w[r], 0};
    }
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
        pushup(u);
    }
}

// void pushdown(int u){
    
//     auto &root = tr[u], &left = tr[u<<1], &right = tr[u<<1|1];
    
//     if (root.add){
//         left.sum += (LL)(left.r - left.l + 1) * root.add;
//         right.sum += (LL)(right.r - right.l + 1) * root.add;
//         left.add += root.add;
//         right.add += root.add;
//         root.add = 0;
//     }
// }

int intersection(int a, int b, int c, int d){
    return min(b, d) - max(a, c) + 1;
}

void modify(int u, int l, int r, int d){
    // 标记永久化，在更改到全覆盖区间前将重合区间贡献值直接加上，全覆盖区间加上add值
    tr[u].sum += intersection(tr[u].l, tr[u].r, l, r) * (LL)d;
    if (tr[u].l >= l && tr[u].r <= r){
        tr[u].add += d;
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u<<1, l, r, d);
        if (r > mid) modify(u<<1|1, l, r, d);
    }
}

   // 查询函数中加上累加的add函数，全覆盖区间加上区间和与本应传下来的add值
LL query(int u, int l, int r, int add){
    if (tr[u].l >= l && tr[u].r <= r){
        return tr[u].sum + (tr[u].r - tr[u].l + 1) * (LL)add;
    }
    add += tr[u].add; // 子区间要加上上面未下传的add值
    int mid = tr[u].l + tr[u].r >> 1;
    LL sum = 0;
    if (l <= mid) sum += query(u<<1, l, r, add);
    if (r > mid) sum += query(u<<1|1, l, r, add);
    return sum;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    build(1, 1, n);
    char o[2];
    int l, r, d;
    while (m --){
        scanf("%s%d%d", o, &l, &r);
        if (*o == 'C'){
            scanf("%d", &d);
            modify(1, l, r, d);
        }
        else {
            printf("%lld\n", query(1, l, r, 0));
        }
    }
    return 0;
}