/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-10 08:50:13
 * @LastEditTime: 2021-03-10 12:38:23
 */

#include <iostream>
#include <cstdio>                             
#include <cstring>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

const int N = 5e4 + 10, M = 1e5 + 5;

int p[N];
int k, n, m, res, ans;

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

struct Node{
    int a, b, c, d;
    bool operator< (const Node &M){
        if (c != M.c){            // 比较方式改变后就过了，为什么c相同时需要比较d？
            return c < M.c;
        }else return d < M.d;
    }
}node[M];

bool kruskal(int x){
    
    res = 0;
    for (int i = 0; i < m; i ++){
        if (!node[i].d){
            node[i].c += x;
        }
    }

    sort(node, node + m);
    int n1 = 0;
    for (int i = 0; i < m; i ++){
        int a = node[i].a, b = node[i].b, c= node[i].c, d = node[i].d;
        int pa = find(a), pb = find(b);
        if (pa != pb){
            p[pa] = pb;
            res += c;
            if (!d) n1 ++;
        }
    }

    for (int i = 0; i < m; i ++){
        if (!node[i].d){
            node[i].c -= x;
        }
    }

    return n1 >= k;
}


int main(){

    int T = 1;
    while (scanf("%d%d%d", &n, &m, &k) != EOF){

        for (int i = 0; i < m; i ++){
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            node[i] = {a, b, c, d};
        }
        int l = -100, r = 100;
        while (l < r){
            for (int i = 0; i <= n; i++) p[i] = i;
            int mid = l + r + 1>> 1;
            if (kruskal(mid)) ans = res - k * mid, l = mid;
            else r = mid - 1;
        }

        printf("Case %d: %d\n", T ++, ans);
    }


    return 0;
}