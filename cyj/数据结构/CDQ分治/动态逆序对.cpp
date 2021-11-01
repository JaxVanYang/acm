/*
 * @Descripttion: 
 * @Topic link: https://www.luogu.com.cn/problem/P3157
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-24 12:46:30
 * @LastEditTime: 2021-08-07 09:59:52
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

struct node {
    int a, v, t;
    ll res;
}q[N], t[N];
int n, m, pos[N], tr[N];
ll ans[N];

int lowbit(int x){
    return x & -x;
}

void add(int x, int y){
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += y;
}

int sum(int x){
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

void merge_sort(int l, int r){
    if(l >= r) return ;
    int mid = l + r >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);
    int i = l, j = mid + 1;
    while (i <= mid && j <= r){
        if (q[i].v > q[j].v) add(q[j].t, 1), j ++;
        else q[i].res += sum(q[i].t-1), i ++;
    }
    while (i <= mid ) q[i].res += sum(q[i].t-1), i ++;
    for (int k = mid + 1; k < j; k ++) add(q[k].t, -1);

    i = mid, j = r;
    while (i >= l && j > mid){
        if (q[i].v > q[j].v) add(q[i].t, 1), i --;
        else q[j].res += sum(q[j].t-1), j --;
    }
    
    while (j > mid) q[j].res += sum(q[j].t-1 j --;
    for (int k = mid; k > i; k --) add(q[k].t, -1);
    i = l, j = mid + 1;
    int  k = 0;
    while ( i <= mid && j <= r){
        if (q[i].v <= q[j].v) t[k ++] = q[i ++];
        else t[k ++] = q[j ++];
    }
    while (i <= mid) t[k ++] = q[i ++];
    while (j <= r) t[k ++] = q[j ++];
    for (int i = 0, j = l; i < k; i ++, j ++) q[j] = t[i];
    //  exit(0);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        int a;
        scanf("%d", &a);
        q[i] = {i, a};
        pos[a] = i;
    }
    for (int i = 1, j = n; i <= m; i ++){
        int a;
        scanf("%d", &a);
        q[pos[a]].t = j --;
        pos[a] = -1;
    }
    for (int i = 1, j = n-m; i <= n; i ++){
        if (pos[i] != -1) {
            if (j )
            q[pos[i]].t = j --;
        }
    }
    merge_sort(1, n);
    
    for (int i = 1; i <= n; i ++) ans[q[i].t] += q[i].res;
    for (int i = 1; i <= n; i ++) ans[i] += ans[i-1];
    for (int i = n, j = 0; j < m; j ++, i --) printf("%lld\n", ans[i]);
    return 0;
}
