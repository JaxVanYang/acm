/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/description/2523/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-29 12:50:50
 * @LastEditTime: 2021-07-29 13:53:36
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 10000, S = 1e6 + 10;

int len, n, m, w[N], qn, mn, cnt[S], ans[N];
struct query{
    int id, l, r, t;
}q[N];

struct modify{
    int p, c;
}md[N];

int get(int x){
    return (x-1) / len;
}

bool cmp(const query& a, const query & b){
    int i = get(a.l), j = get(b.l), x = get(a.r), y = get(b.r);
    if (i != j) return i < j;
    if (x != y) return x < y;
    return a.t < b.t;
}

void add(int x, int &res){
    if (!cnt[x]) res++;
    cnt[x] ++;
}

void del(int x, int &res){
    cnt[x] --;
    if (!cnt[x]) res --;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i =1 ; i <= n; i ++) scanf("%d", &w[i]);
    char op[3];
    int a, b;
    while (m --){
        scanf("%s", op);
        if (*op == 'Q'){
            scanf("%d%d", &a, &b);
            qn ++;
            q[qn] = {qn, a, b, mn};
        }
        else {
            scanf("%d%d", &a, &b);
            md[++ mn] = {a, b};
        }
    }
    // len = cbrt((double)n * mn) + 1; // 此处记得加1，若数比较小开三次方会变为0
    // len = sqrt(n);
    len = pow(n, 0.666);
    sort(q+1, q + qn + 1, cmp);
    for (int i = 1, j = 0, res = 0, t = 0, k = 1; k <= qn; k ++){
        int id = q[k].id, l = q[k].l, r = q[k].r, t1 = q[k].t;
        while (j < r) add(w[++ j], res);
        while (j > r) del(w[j --], res);
        while (i > l) add(w[-- i], res);
        while (i < l) del(w[i ++], res);
        while (t < t1){
            t ++;
            if (md[t].p >= l && md[t].p <= r){
                del(w[md[t].p], res);
                add(md[t].c, res);
            }
            swap(w[md[t].p], md[t].c);
        }
        while (t > t1){
            if (md[t].p >= l && md[t].p <= r){
                del(w[md[t].p], res);
                add(md[t].c, res);
            }
            swap(w[md[t].p], md[t].c);
            t --;
        }
        ans[id] = res;
    }
    for (int i = 1; i <= qn; i ++) printf("%d\n", ans[i]);
    return 0;
}