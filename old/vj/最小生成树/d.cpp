/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-10 08:50:13
 * @LastEditTime: 2021-03-10 09:25:11
 */

#include <iostream>
#include <cstdio>                               // 思路错误
#include <cstring>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

const int N = 5e4 + 10, M = 1e5 + 5;

int p[N];
int k, n, m;

struct Node{
    int a, b, c, d;
    bool operator< (const Node &M){
        return c < M.c;
    }
}node[M];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){

    int T = 1;
    while (scanf("%d%d%d", &n, &m, &k) != EOF){

        for (int i = 1; i <= n; i++) p[i] = i;

        for (int i = 0; i < m; i ++){
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            node[i] = {a, b, c, d};
        }

        sort(node, node + m);
        int res = 0, n1 = 0, n2 = 0;
        for (int i = 0; i < m; i ++){
            int a = node[i].a, b = node[i].b, c= node[i].c, d = node[i].d;
            int pa = find(a), pb = find(b);
            if (pa != pb){
                if ((!d && n1 <= k) || (d && n2 <= (n-1-k))){
                    p[pa] = pb;
                    res += c;
                    if (!d) n1 ++;
                    else n2 ++;
                }
            }
        }

        printf("Case %d: %d\n", T ++, res);
    }


    return 0;
}