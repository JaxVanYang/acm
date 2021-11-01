/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/description/2173/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-08 13:39:41
 * @LastEditTime: 2021-08-08 13:39:59
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, M = 20010, INF = 1e8;
int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
int d[N], st[N], q[N], pre[N];

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx ++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx ++;
}

bool bfs(){
    int hh = 0, tt = 0;
    memset(st, 0, sizeof st);
    q[0] = S, d[S] = INF, st[S] = 1;
    while (hh <= tt){
        int t = q[hh ++];
        if (t == T) return true;
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (!st[j] && f[i]){
                st[j] = 1, q[++ tt] = j;
                d[j] = min(d[t], f[i]);
                pre[j] = i;
            }
        }
    }
    return false;
}

int EK(){
    int r = 0;
    int tim = 0;
    while (bfs()){
        r += d[T];
        // 此处最好用for循环，while难以判断起点后第一条边，虽pre[S]为0，但第一条边编号也为0
        for (int i = T; i != S; i = e[pre[i] ^ 1]){
            f[pre[i]] -= d[T], f[pre[i] ^ 1] += d[T];
        }
    }
    return r;
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d%d%d", &n, &m, &S, &T);
    for (int i = 1; i <= m; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    printf("%d\n", EK());
    return 0;
}