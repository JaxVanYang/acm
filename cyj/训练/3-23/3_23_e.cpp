/*
 * @Descripttion: TLE版本，过于暴力
 * @Topic link: https://vjudge.net/contest/429156#problem/E
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-23 20:14:51
 * @LastEditTime: 2021-03-24 09:08:50
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

int ne[N * 2], e[N * 2], w[N * 2], h[N], idx;
int p[N], res;
int v[N], cnt;
bool st[N];
struct Edge
{
    int a, b, c;
    bool operator< (const Edge &m) {
        return c < m.c;
    }
}edge[M];

int n ,m, q, s;

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int dfs(int t){
    st[t] = true;
    int num = 1;
    for (int i = h[t]; ~i; i = ne[i]){
        int j = e[i];
        if (w[i] < s && !st[j]){
            num += dfs(j);
        }
    }
    return num;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T --){
        idx = 0;
        for (int i = 0; i <= n; i ++) h[i] = -1;
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 0; i < m; i ++){
            int a, b ,c;
            scanf("%d%d%d", &a, &b, &c);
            edge[i] = {a, b, c};
        }

        for (int i = 1; i <= n; i ++) p[i] = i;
        sort(edge, edge + m);
        for (int i = 0; i < m; i ++){
            int a = edge[i].a, b = edge[i].b, c = edge[i].c;
            int pa = find(a), pb = find(b);
            if (pa != pb){
                p[pa] = pb;
                add(a, b, c), add(b, a, c);
            }
        }
        for (int i = 0; i < q; i++){
            res = cnt = 0;
            for (int i = 1; i <= n; i++) st[i] = 0;
            scanf("%d", &s);
            for (int i = 1; i <= n;  i++){
                if (!st[i]){
                    v[++ cnt] = dfs(i);
                    if (v[i] == 1) continue;
                    else res += v[i] * (v[i] - 1) / 2;
                }
            }
            printf("%d\n", res * 2);
        }
    }
    return 0;
}
