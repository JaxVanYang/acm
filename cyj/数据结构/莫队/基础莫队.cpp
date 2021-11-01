/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-28 15:05:20
 * @LastEditTime: 2021-08-07 15:44:25
 */
/*
 * @Descripttion: 
 HH 有一串由各种漂亮的贝壳组成的项链。
HH 相信不同的贝壳会带来好运，所以每次散步完后，他都会随意取出一段贝壳，思考它们所表达的含义。
HH 不断地收集新的贝壳，因此他的项链变得越来越长。
有一天，他突然提出了一个问题：某一段贝壳中，包含了多少种不同的贝壳？
这个问题很难回答，因为项链实在是太长了。

即每一段询问中有多少个不同的数

于是，他只好求助睿智的你，来解决这个问题。
 * @Topic link: https://www.acwing.com/problem/content/description/2494/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-28 15:05:20
 * @LastEditTime: 2021-07-28 15:05:44
 */

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int N  = 5e4 + 10, M = 2e5 + 10, S = 1e6 + 10;

int ans[M], w[N];
struct Query{
    int id, l, r;
}q[M];
int cnt[S], n, m, len;

int get(int x){
    return (x-1) / len;
}

bool cmp(const Query& a, const Query& b){
    int i = get(a.l), j = get(b.l);
    if (i != j) return i < j;
    else {
        if (i & 1) return a.r > b.r;
        else return a.r < b.r;
    }
}

void add(int x, int & res){
    if (!cnt[x]) res ++;
    cnt[x] ++;
}

void del(int x, int &res){
    cnt[x] --;
    if (!cnt[x]) res --;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    scanf("%d", &m);
    len = sqrt((double)n * n / m); // 此处注意用double，会爆int
    for (int i = 0; i < m; i ++){
        int l, r;
        scanf("%d%d", &l, &r);
        q[i] = {i, l, r};
    }
    sort(q, q + m, cmp); 
    for (int k = 0, i = 0, j = 1, res = 0; k < m; k ++){
        int id = q[k].id, l = q[k].l, r = q[k].r;
        while (i < r) add(w[ ++ i], res);
        while (i > r) del(w[i --], res);
        while (j < l) del(w[j ++], res);
        while (j > l) add(w[-- j], res);
        ans[id] = res;
    }
    for (int i = 0; i < m; i ++) printf("%d\n", ans[i]);
    return 0;
}