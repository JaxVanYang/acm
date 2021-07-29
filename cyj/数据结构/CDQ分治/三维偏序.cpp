/*
 * @Descripttion: cdq分治板子
 * @Topic link: https://www.acwing.com/problem/content/2817/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-23 23:26:51
 * @LastEditTime: 2021-07-23 23:27:41
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;;

int n, m;
struct node{
    int a, b, c, cnt, res;
    bool operator< (const node &m) const {
        if (a != m.a) return a < m.a;
        if (b != m.b) return b < m.b;
        return c < m.c;
    }
    bool operator== (const node &m)const {
        return a == m.a && b == m.b && c == m.c;
    }
}q[N], t[N];
int tr[M], ans[N];

int lowbit(int x){
    return x & -x;
}

void add(int x, int y){
    for (int i = x; i < M; i += lowbit(i)) tr[i] += y;
}

int sum(int x){
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

void merge_sort(int l, int r){
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r){
        if (q[i].b <= q[j].b) add(q[i].c, q[i].cnt), t[k ++] = q[i ++];
        else q[j].res += sum(q[j].c), t[k++] = q[j++];
    }
    while (i <= mid) add(q[i].c, q[i].cnt), t[k ++] = q[i ++];
    while (j <= r) q[j].res += sum(q[j].c), t[k++] = q[j++];
    for (int i = l; i <= mid; i ++) add(q[i].c, -q[i].cnt);
    for (int i = 0, j = l; i < k; i ++, j ++) q[j] = t[i];
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        q[i] = {a, b, c, 1};
    }
    sort(q, q + n);
    int k = 1;
    for (int i = 1; i < n; i ++){
        if (q[i] == q[k-1]) q[k-1].cnt ++;
        else q[k ++] = q[i];
    }
    merge_sort(0, k-1);
    for (int i = 0; i < k; i ++){
        ans[q[i].res + q[i].cnt - 1] += q[i].cnt;
    }
    for (int i = 0; i < n; i ++) printf("%d\n", ans[i]);
    return 0;
}