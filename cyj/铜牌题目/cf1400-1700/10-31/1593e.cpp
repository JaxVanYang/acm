/*
 * @Descripttion: 拓扑序bfs
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-10-31 15:50:11
 * @LastEditTime: 2021-10-31 16:11:41
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 4e5 + 10, M = 8e5 + 10;
int n, k;
int h[N], e[M], ne[M], idx;
int q[N];
int in[N], d[N];
bool st[N];
int num;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void bfs(){
    memset(d, 0, sizeof d);
    int hh = 0,tt = -1;
    for (int i = 1; i <= n; i ++){
        if (in[i] == 1) q[++ tt] = i, d[i] = 1, num ++;
    }
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (--in[j] == 1 && !st[j] && d[t] + 1 <= k){
                st[j] = 1, num ++;
                d[j] = d[t] + 1;
                q[++ tt] = j;
            }
        }
    }
    printf("%d\n", n - num);
}

void solve(){
    idx = num = 0;
    memset(h, -1, sizeof h);
    memset(st, 0, sizeof st);
    memset(in, 0, sizeof in);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n-1; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a ,b), add(b, a);
        in[a] ++, in[b] ++;
    }
    if (n == 1 || n == 2) {
        puts("0");
        return;
    }
    bfs();
}

int main(){
    int T;
    cin >> T;
    while (T --){
        solve();
    }
    return 0;
}