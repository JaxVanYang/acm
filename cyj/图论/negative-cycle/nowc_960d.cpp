/*
 * @Descripttion: 21 03 20 pan
 * @Topic link: https://ac.nowcoder.com/acm/contest/960/D
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-22 20:59:53
 * @LastEditTime: 2021-03-22 21:00:11
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 5300;

int e[M], ne[M], w[M], idx, h[N];
int n, m1, m2;
int cnt[N]; // 每个点当前最短路径的长度
bool st[N];
int dist[N];

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

bool spfa(){
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    int hh = 0, tt = 0;
    int q[N];
    for (int i = 1; i <= n; i ++){
        q[tt ++] = i;
        st[i] = true;
    }
    while (hh != tt){
        int t = q[hh ++];
        if (hh == N) hh = 0;
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!st[j]){
                    q[tt ++] = j;
                    if (tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
    
    return false;
}

int main(){
    
    int T;
    scanf("%d",&T);
    while (T --){
        idx = 0;
        memset(h, -1, sizeof h);
        scanf("%d%d%d", &n, &m1, &m2);
        for (int i = 0; i < m1;  i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add (a, b, c), add(b, a, c);
        }
        
        for (int i = 0; i < m2 ; i ++){
            int a ,b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, -c);
        }
        if (spfa()) puts("YES");
        else puts("NO");
    }
    
    return 0;
}
