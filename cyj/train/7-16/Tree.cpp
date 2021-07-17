/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: Wrong Answer
 * @Author: cyj
 * @Date: 2021-07-16 17:08:32
 * @LastEditTime: 2021-07-16 17:15:55
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, mod = 1e9 + 7;
typedef long long ll;
int n;
int h[N], e[M], ne[M], idx;
ll f[N];
//591857147
int qmi(ll x, int k){
    int res = x % mod;
    while (k){
        if (k & 1) res = (ll)res * x % mod;
        k >>= 1;
        x = (ll)x * x % mod;
    }
    return res;
    cout << res << endl;
}

int mul(int x){
    return qmi(x, mod - 2);
}

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a]  =idx ++;
}

ll dfs1(int u, int fa){
    f[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (j == fa) continue;
        ll t = dfs1(j, u);
        f[u] = (f[u] * (t + 1)) % mod;
    }
    return f[u];
}

void dfs2(int u, int fa){
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (j == fa) continue;
//        f[j] = (f[j] % mod * ((f[u] / (f[j] + 1)) + 1)) % mod;
        f[j] = (f[j] * ((f[u] * mul(f[j] + 1)) % mod + 1)) % mod;
        // 二者相除后取模不等于取模后相除
        dfs2(j, u);
    }
}

int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    // dfs1(1, -1);
    // dfs2(1, -1);
//     for (int i = 1; i <= n; i ++) cout << f[i] << endl;
cout << qmi(100, 1e9);
    return 0;
}
