/*
 * @Descripttion: 
 * @Topic link: https://www.luogu.com.cn/problem/P3758
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-30 15:43:22
 * @LastEditTime: 2021-08-08 11:08:15
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

const int N = 1e6 + 5, mod = 2017;
typedef long long LL;
typedef pair<int, int> PII;

int f[N][32];
int n, m, tim;
int h[33], e[400], ne[400], idx;
// f[i][j] 表示走了i步，当前在j点时的方案总数（在n+1处说明已自爆）

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    for (int i = 1; i <= n; i ++) add(i, n+1), add(i, i); // n + 1 为自爆点，任何点可走向自爆点，自爆点不能返回
    add(n+1, n+1); 
    scanf("%d", &tim);
    f[0][1] = 1;
    for (int i = 0; i <= tim; i ++){
        for (int j = 1; j <= n + 1; j ++){
            for (int k = h[j]; ~k; k = ne[k]){
                f[i+1][e[k]] = (f[i+1][e[k]] + f[i][j]) % mod;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n + 1; i ++) {
        res = (res + f[tim][i]) % mod;
    }
    printf("%d\n", res);
    return 0;
}