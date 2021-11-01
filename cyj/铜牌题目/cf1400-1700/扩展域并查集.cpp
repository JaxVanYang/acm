/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-10-26 14:45:58
 * @LastEditTime: 2021-10-26 16:14:28
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 2e5 + 10, M = 5e5 + 10;

int T, n, m;
int st[N], q[N];
int p[N * 2], size[N * 2];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void unionall(int a, int b){
    int pa = find(a), pb = find(b);
    if (pa != pb){
        p[pa] = pb;
        size[pb] += size[pa];
        size[pa] = 0;
    }
}

void solve(){    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2 * n; i ++){
        if (i <= n) size[i] = 0;
        else size[i] = 1;
        p[i] = i;
    }
    for (int i = 0; i < m; i ++){
        int a, b;
        char s[20];
        scanf("%d%d%s", &a, &b, &s);
        if (s[0] == 'i'){
            unionall(a, b + n), unionall(b, a + n);
        }else unionall(a, b), unionall(a +n, b + n);
    }
    int num = 0;
    for (int i = 1; i <= n; i ++){
        int a = i, b = i + n;
        int pa = find(a), pb = find(b);
        if (pa == pb){
            puts("-1");
            return;
        }
        if (pa == a) num += max(size[pa], size[pb]);
        if (pb == b) num += max(size[pa], size[pb]);
    }
    printf("%d\n", num/2);
}

int main(){
    scanf("%d", &T);
    while (T --){
        solve();
    }
    return 0;
}