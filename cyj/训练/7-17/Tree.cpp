/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/problem/19782
来源：牛客网

修修去年种下了一棵树，现在它已经有n个结点了。
修修非常擅长数数，他很快就数出了包含每个点的连通点集的数量。
澜澜也想知道答案，但他不会数数，于是他把问题交给了你
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-17 09:46:15
 * @LastEditTime: 2021-07-17 09:46:25
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 10, M = 2 * N, mod = 1e9 + 7;
typedef long long ll;
int h[N], e[M], ne[M], idx;
int n;
ll f[N], ans[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa){
    f[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (j == fa) continue;
        dfs(j, u);
        f[u] = f[u] * (f[j] + 1) % mod;
    }
}

ll qmi(int a, int k){
    ll res = 1 % mod;
    while (k){
        if (k & 1) res = res * a % mod;
        k >>= 1;
        a = (ll)a * a % mod;
    }
    return res % mod;
}

void dfs2(int u, int fa){
    for (int i = h[u]; ~i; i =ne[i]){
        int j = e[i];
        if (j == fa) continue;
        if ((f[j] + 1) % mod == 0){
            ll tmp = 1;
            for (int i = h[u];~i; i =ne[i]){
                int son = e[i];
                if (son == fa || son == j) continue;
                tmp = (tmp * (f[son] + 1)) % mod;
            }
            ans[j] = (f[j] * (tmp + 1)) % mod;
        }
        else {
            int x = qmi((f[j] + 1), mod -2);
            ans[j] = f[j] % mod * (ans[u] * x % mod + 1) % mod;
        }
        dfs2(j, u);
    }
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i < n; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1, -1);
    ans[1] = f[1];
    dfs2(1, -1);
    for (int i = 1; i <= n; i ++) cout << ans[i] << endl;
    
    
    return 0;
}