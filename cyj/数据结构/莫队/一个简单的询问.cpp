/*
 * @Descripttion: 
 给你一个长度为 N 的序列 ai，1≤i≤N，和 q 组询问，每组询问读入 l1,r1,l2,r2，需输出

    ∑x=0∞get(l1,r1,x)⋅get(l2,r2,x)
get(l,r,x) 表示计算区间 [l,r] 中，数字 x 出现了多少次。
 * @Topic link: https://www.acwing.com/problem/content/description/3041/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-28 21:46:25
 * @LastEditTime: 2021-07-28 21:46:53
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 5e4 + 5, M = N * 4;

struct Ask {
    int l1, r1 ,l2, r2;
}ask[N];

map<int, map<int , ll>> ans;
struct query{
    int l, r;
}q[M];
int n, m, w[N], len;
ll tmp[N], tmp2[N], res;

int get(int x){
    return (x-1)/len;
}

bool cmp(const query& a, const query& b){
    int i = get(a.l), j = get(b.l);
    if (i != j) return i < j;
    else {
        return a.r < b.r;
    }
}

void add(int x, ll *t1, ll *t2){
    res -= t1[w[x]] * t2[w[x]];
    t1[w[x]] ++;
    res += t1[w[x]] * t2[w[x]];
}

void del(int x, ll *t1, ll *t2){
    res -= t1[w[x]] * t2[w[x]];
    t1[w[x]] --;
    res += t1[w[x]] * t2[w[x]];
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    scanf("%d", &m);
    // len = (sqrt((double)n * n / (m * 4)));
    len = sqrt(n);
    for (int i = 1; i <= m; i ++) {
        int l1, l2, r1, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        ask[i] = {l1, r1, l2 ,r2};
        q[i * 4 - 3] = {r1, r2};
        q[i * 4 - 2] = {r1, l2 - 1};
        q[i * 4 - 1] = {l1-1, r2};
        q[i * 4] = {l1-1, l2 - 1};
    }
    sort(q + 1, q + m*4 + 1, cmp);
    for (int k = 1, i = 1, j = 0; k <= m * 4; k ++){
        int l = q[k].l, r = q[k].r;
        while (j < r) add(++ j, tmp2, tmp);
        while (j > r) del(j --, tmp2, tmp);
        while (i < l) add(++ i, tmp, tmp2);
        while (i > l) del(i --, tmp, tmp2);
        ans[l][r] = res;
    }
    for (int i = 1; i <= m; i ++){
        auto &t = ask[i];
        int l1 = t.l1, r1 = t.r1, l2 = t.l2, r2 = t.r2; 
        printf("%lld\n", ans[r1][r2] - ans[r1][l2 - 1] - ans[l1-1][r2] + ans[l1-1][l2-1]);
    }
    return 0;
}