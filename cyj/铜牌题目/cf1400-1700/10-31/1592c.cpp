/*
 * @Descripttion: 巧妙运用了异或的性质 x^x=0, x^x^x  = x，利用dfs来进行边的切割
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-10-31 19:45:42
 * @LastEditTime: 2021-10-31 20:06:40
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int h[N], e[N * 2], ne[N * 2], idx;
int n, m, k;
int a[N], s[N], num;

void add(int a, int b){
    e[idx] = b, ne[idx]  = h[a], h[a] = idx ++;
}

int dfs(int u, int fa){
    int res = a[u];
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (j == fa) continue;
        int t = dfs(j, u);
        if (t == s[n]){
            num ++;
        }else res ^= t;
    }
    return res;
}

int main(){
    int T;
    scanf("%d", &T);
    while (T --){
        idx = num = 0;
        memset(h, -1, sizeof h);
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), s[i] = a[i], s[i] ^= s[i-1];
        for (int i = 1; i < n; i ++){
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b), add(b, a);
        }
        if (s[n] == 0) {
            puts("Yes");
            continue;
        }else {
            dfs(1, -1);
            if (num > 1 && k >= 3) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}