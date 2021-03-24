/*
 * @Descripttion: 
 * @Topic link: https://ac.nowcoder.com/acm/contest/961/C
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-24 16:01:53
 * @LastEditTime: 2021-03-24 16:09:16
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N  = 1e5 + 5, M = 3e5 + 10;

typedef long long LL;
LL dist[N];
int n, k;
bool st[N];
int q[N], cnt[N];
int ne[M], e[M], h[N], w[M], idx;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

bool spfa(){
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;
    int hh = 0, tt = 0;
    q[tt ++] = 0;
    st[0] = true;
    while (hh != tt){
        int t = q[hh ++];
        if (hh == N) hh = 0;
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n + 1) return true;
                if (!st[j]){
                    q[tt ++] = j;
                    if (tt == N) tt = 0;
                    st[t] = true;
                }
            }
        }
    }
    
    return false;
}

int main(){
    scanf("%d%d", &n, &k);
    memset(h, -1, sizeof h);
    for (int i = 0; i < k; i ++){
        int x, a, b;
        scanf("%d%d%d", &x, &a, &b);
        if (x == 1) add(a, b, 0), add(b, a, 0);
        else if (x == 2) add(a, b, 1);
        else if (x == 3) add(b, a, 0);
        else if (x == 4) add(b, a, 1);
        else add(a, b, 0);
    }
    for (int i = 1; i <= n; i ++) add(0, i, 1);
    
    if (spfa()) puts("-1");
    else {
        LL res = 0;
        for (int i = 1; i <= n; i ++) res += dist[i], cout << dist[i] << " ";
//         printf("%lld\n", res);
    }
    
    return 0;
}