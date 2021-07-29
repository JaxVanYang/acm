/*
 * @Descripttion: 
    HH 有一串由各种漂亮的贝壳组成的项链。
    HH 相信不同的贝壳会带来好运，所以每次散步完后，他都会随意取出一段贝壳，思考它们所表达的含义。
    HH 不断地收集新的贝壳，因此他的项链变得越来越长。
    有一天，他突然提出了一个问题：某一段贝壳中，包含了多少种不同的贝壳？
    这个问题很难回答，因为项链实在是太长了。

    即每一段询问中有多少个不同的数  
 * @Topic link: https://www.luogu.com.cn/problem/P1972
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-28 16:21:26
 * @LastEditTime: 2021-07-28 16:25:11
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int tr[N], n, m, w[N], ans[N], ls[N];
struct query{
    int l, r, id;
    bool operator< (const query& m) const {
        return r < m.r;
    }
}q[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y){
    for (int i = x; i < N; i += lowbit(i)) tr[i] += y;
}

int sum(int x){
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    scanf("%d", &n);;
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    scanf("%d", &m);
    for (int i = 0; i < m;  i++){
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q, q + m); // 根据询问区间右端点排序
    for (int i = 0, j = 1; i < m; i ++){
        int id = q[i].id, l = q[i].l, r = q[i].r;
        for (; j <= r; j ++){
            if (ls[w[j]]) add(ls[w[j]], -1);  // 当前数在前面位置出现过，将其删去，加到当前点，更新此点最近的位置
            add(j, 1), ls[w[j]] = j;
        }
        ans[id] = sum(r) - sum(l-1);
    }
    for (int i = 0; i < m; i ++) printf("%d\n", ans[i]);
    return 0;
}