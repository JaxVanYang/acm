/*
 * @Descripttion: 
 给定一个长度为 N 的数列 A，以及 M 条指令，每条指令可能是以下两种之一：

    C l r d，表示把 A[l],A[l+1],…,A[r] 都加上 d。
    Q l r，表示询问数列中第 l∼r 个数的和。
    对于每个询问，输出一个整数表示答案。
 * @Topic link: https://www.acwing.com/problem/content/description/244/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-27 19:57:56
 * @LastEditTime: 2021-07-27 20:02:36
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = 350; // 分为根号n个区间进行操作

typedef long long ll;

ll add[M], sum[M];
int w[N], len, n, m;

int get(int x){ // 映射属于哪一个块
    return (x-1) / len;
}

void change(int l, int r, int x){
    if (get(l) == get(r)){ // 若在一个区间内，直接暴力
        for (int i = l; i <= r; i ++) w[i] += x, sum[get(i)] += x;
        return;
    }
    // 先暴力处理两边，再区间处理中间块
    int i = l, j = r;
    while (get(i) == get(l)) w[i] += x, sum[get(i)] += x, i ++;
    while (get(j) == get(r)) w[j] += x, sum[get(j)] += x, j --;
    for (int k = get(i); k <= get(j); k ++) sum[k] += len * x, add[k] += x;
}

ll query(int l, int r){
    ll res = 0;
    if (get(l) == get(r)){ // 若在一个块内，直接暴力
        for (int i = l; i <= r; i ++) res += w[i] + add[get(i)];
    }
    else { // 否则暴力处理两边，再处理中间块
        int i = l, j = r;
        while (get(i) == get(l)) res += w[i] + add[get(i)], i ++;
        while (get(j) == get(r)) res += w[j] + add[get(j)], j --;
        // 整区间的sum在change时已经处理，add标记给暴力查询的数记录需要增加的值
        for (int k = get(i); k <= get(j); k ++) res += sum[k]; 
    }
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    len = sqrt(n);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]), sum[get(i)] += w[i];
    char op[2];
    int l, r, x;
    while (m --){
        scanf("%s", op);
        if (*op == 'C'){
            scanf("%d%d%d", &l, &r, &x);
            change(l, r, x);
        }else {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(l, r));
        }
    }
    
    return 0;
}