/*
 * @Descripttion: 
 * @Topic link: https://ac.nowcoder.com/acm/contest/961/A
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-24 17:38:24
 * @LastEditTime: 2021-03-24 17:40:32
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5e5 + 5, M = 1e6 + 10;

int ne[M], e[M], h[N], w[M], idx;
int s[N], dist[N];
bool st[N];
typedef pair<int, int> PII;

PII query[N];
int n, c[N];
int maxn; // 记录选数区间的右端点

void add(int x, int y, int z){
    e[idx] = y, ne[idx] = h[x], w[idx] = z, h[x] = idx ++;
}

void spfa(){
    memset(dist, -0x3f, sizeof dist);
    int q[N];
    dist[0] = 0;
    int hh = 0, tt = 0;
    q[tt ++] = 0;
    st[0] = true;
    while (hh != tt){
        int t = q[hh ++];
        if (hh == N) hh = 0;
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if (dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if (!st[j]){
                    q[tt ++] = j;
                    if (tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
}

int main(){
    
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        x ++, y ++;
        maxn = max(maxn, y);
        query[i].first = x, query[i].second = y, c[i] = z;
        add(x - 1, y, z);
    }
    for (int i = 1; i <= maxn; i ++){
        add(i, i-1, -1);
        add(i -1, i, 0);
    }
    
    spfa();
    
    printf("%d\n", dist[maxn]);
    
    
    return 0;
}