/*
 * @Descripttion: 
 请你写出一种数据结构，来维护一个长度为 n 的序列，其中需要提供以下操作：
1 pos x，将 pos 位置的数修改为 x。
2 l r x，查询整数 x 在区间 [l,r] 内的前驱(前驱定义为小于 x，且最大的数)。
数列中的位置从左到右依次标号为 1∼n。

区间 [l,r] 表示从位置 l 到位置 r 之间（包括两端点）的所有数字。

区间内排名为 k 的值指区间内从小到大排在第 k 位的数值。（位次从 1 开始）
 * @Topic link: https://www.acwing.com/problem/content/2490/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-24 17:44:00
 * @LastEditTime: 2021-07-24 17:44:12
 */

#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

const int N = 50010, INF = 1e9;

struct node {
    int l, r;
    multiset<int> s;
}tr[N * 4];
int n, m, w[N];

void build(int u, int l, int r){
    tr[u] = {l, r};
    tr[u].s.insert(-INF), tr[u].s.insert(INF);
    for (int i = l; i <= r; i ++) tr[u].s.insert(w[i]);
    if (l == r) return;
    int mid = l + r >> 1;
    build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
}

void modify(int u, int x, int v){
    tr[u].s.erase(tr[u].s.find(w[x]));
    tr[u].s.insert(v);
    if (tr[u].l == tr[u].r) return;
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) modify(u<<1, x, v);
    else modify(u<<1|1, x, v);
}

int query(int u, int l, int r, int x){
    if (tr[u].l >= l && tr[u].r <= r){
        auto it = tr[u].s.lower_bound(x);
        -- it;
        return *it;
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        int res = -INF;
        if (l <= mid) res = max(res, query(u<<1, l, r, x));
        if (r > mid) res = max(res, query(u<<1|1, l, r, x));
        return res;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;  i++) scanf("%d", &w[i]);
    build(1, 1, n);
    while (m --){
        int o;
        scanf("%d", &o);
        if (o == 1){
            int pos, x;
            scanf("%d%d", &pos, &x);
            modify(1, pos, x);
            w[pos] = x;
        }
        else {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            printf("%d\n", query(1, l, r, x));
        }
    }
    
    return 0;
}