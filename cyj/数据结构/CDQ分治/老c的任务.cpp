/*
 * @Descripttion: 
 * @Topic link: https://www.luogu.com.cn/problem/P3755
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-24 09:50:21
 * @LastEditTime: 2021-07-24 09:50:44
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5e5 + 10; // 每个查询有四个点
typedef long long ll;
struct node {
    int x, y, z, v, id, sign;
    ll sum;
    bool operator< (const node &m) const {
        if (x != m.x) return x < m.x;
        if (y != m.y) return y < m.y;
        return z < m.z;
    }
}q[N], t[N];
int n, m;
ll ans[N];

void merge_sort(int l, int r){
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    ll sum = 0;
    while (i <= mid && j <= r){
        if (q[j].y >= q[i].y) sum += !q[i].z * q[i].v,  t[k ++] = q[i ++];
        else q[j].sum += sum, t[k ++] = q[j ++];
    }
    while (i <= mid) sum += !q[i].z * q[i].v,  t[k ++] = q[i ++];
    while (j <= r) q[j].sum += sum, t[k ++] = q[j ++];
    for (int i = 0, j = l; i < k; i ++, j ++) q[j] = t[i];
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        q[i] = {a, b, 0, c};
    }
    int k = n;
    for (int i = 1; i <= m; i ++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        q[k ++] = {x2, y2, 1, 0, i, 1};
        q[k ++] = {x1 - 1, y2, 1, 0, i, -1};
        q[k ++] = {x2, y1-1, 1, 0, i, -1};
        q[k ++] = {x1-1, y1-1, 1, 0, i, 1};
    }
    sort(q, q + k);
    merge_sort(0, k-1);
    for (int i = 0; i < k; i ++){
        if (q[i].z) ans[q[i].id] += q[i].sum * q[i].sign;
    }
    for (int i = 1; i <= m; i ++) printf("%lld\n", ans[i]);
    return 0;
}