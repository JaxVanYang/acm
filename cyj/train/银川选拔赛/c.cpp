/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-28 09:35:08
 * @LastEditTime: 2021-04-28 11:17:59
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 2e3 + 10, mod = 998244353;
typedef long long LL;
int e[N], ne[N], h[N], idx;
int n, m, k;
LL f[N][N], pr[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(h, -1, sizeof h);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++) cin >> pr[i];
    for (int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    f[1][0] = 1;
    if (pr[1] <= k) f[1][pr[1]] = 1;
    for (int i = 1; i <= n; i ++){
        for (int j = 0; j <= k; j ++){
            for (int k = h[i]; ~k; k = ne[k]){
                int v = e[k];
                f[v][j] = (f[v][j] + f[i][j]) % mod;
                if (j >= pr[v]) f[v][j]  = (f[v][j] + f[i][j-pr[v]]) % mod;
            }
        }
    }
    LL res = 0;
    for (int i = 0; i <= k; i ++){
        res = (res + f[n][i]) % mod;
    }
    cout << res << endl;
    return 0;
}