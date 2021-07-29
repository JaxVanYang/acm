/*
 * @Descripttion: 
 * @Topic link: https://vjudge.net/contest/429156#problem/E
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-24 09:09:12
 * @LastEditTime: 2021-03-24 12:16:47
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

const int N = 2e4 + 5, M = 2e5 + 5, mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;

int res, cnt;
int ans[5010];
int p[N], s[N];

struct Edge
{
    int a, b, c;
    bool operator< (const Edge &m) {
        return c < m.c;
    }
}edge[M];

PII query[5010]; // first存询问数值，second存编号，按编号输出

int n ,m, q;

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    int T;
    scanf("%d", &T);
    while (T --){
        memset(ans, 0, sizeof ans);
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i ++){
            p[i] = i;
            s[i] = 1;
        }
        
        for (int i = 0; i < m; i ++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edge[i] = {a, b, c};
        }
        sort(edge, edge + m); 
        for (int i = 0; i < q; i ++){
            int x;
            scanf("%d", &x);
            query[i] = {x, i};
        }
        sort(query, query + q); // 从小到大排序，依次处理
        res = 0, cnt = 0;
        for (int i = 0; i < m; i ++){
            int a = edge[i].a, b = edge[i].b, c = edge[i].c;
            int pa = find(a), pb = find(b);
            while (c > query[cnt].first && cnt < q){ // 当没有新边可加入时，询问的返回值与之前相同
                ans[query[cnt].second] = res;
                cnt ++;
            }
            if (pa != pb){
                res += (s[pa] + s[pb]) * (s[pa] + s[pb] - 1);
                res -= (s[pa] - 1) * s[pa] + (s[pb] - 1) * s[pb];
                p[pa] = pb;
                s[pb] += s[pa];
            }
        }
        
        while (cnt < q) ans[query[cnt ++].second] = res; // 当边都加完时还有询问没有处理时，说明后面的q也都一定可以满足
        for (int i = 0; i < q; i ++) printf("%d\n", ans[i]);
    }
    

    return 0;
}
