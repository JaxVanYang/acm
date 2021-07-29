/*
 * @Descripttion: 
 强连通分量缩点后拓扑序dp求最长链
 * @Topic link: https://ac.nowcoder.com/acm/contest/962/B
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-19 20:03:29
 * @LastEditTime: 2021-07-19 20:04:03
 */

#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 1e5 + 10, M = 2e6 + 10;
typedef long long ll;
int dfn[N], low[N], timestamp;
int id[N], scc_cnt;
int h[N], e[M], ne[M], idx, h1[N];
int n, m, mod;
int stk[N], top, size[N];
bool in_stk[N];
unordered_set<ll> s;
ll f[N], num[N];

void tarjan(int u){
    dfn[u] = low[u] = ++ timestamp;
    stk[++ top] = u, in_stk[u] = 1;
    for (int i = h[u]; ~i; i=ne[i]){
        int j = e[i];
        if (!dfn[j]){
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
    }
    if (low[u] == dfn[u]){
        int y;
        ++ scc_cnt;
        do{
            y = stk[top --];
            id[y] = scc_cnt;
            in_stk[y] = 0;
            size[scc_cnt] ++;
        } while (y != u);
    }
}

void add(int h[], int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int main(){
    cin >> n >> m >> mod;
    memset(h, -1, sizeof h);
    memset(h1, -1, sizeof h1);
    for (int i = 1; i <= m; i ++){
        int a ,b;
        cin >> a >> b;
        add(h, a, b);
    }
    for (int i = 1; i<= n; i ++){
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i ++){
        for (int j = h[i]; ~j; j = ne[j]){
            int a = id[i], b = id[e[j]];
            if (a != b){
                ll hash = a * 100000 + b;
                if (!s.count(hash)){
                    add(h1, a, b);
                    s.insert(hash);
                }
                
            }
        }
    }
    for (int i = scc_cnt; i ; i --){
        if (!f[i]){
            f[i] = size[i], num[i] = 1;
        }
        for (int j = h1[i]; ~j; j = ne[j]){
            int son = e[j];
            if (f[i] + size[son] > f[son]){
                f[son] = f[i] + size[son];
                num[son] = num[i];
            }
            else if (f[i] +size[son] == f[son]){
                num[son] = (num[i] + num[son]) % mod;
            }
        }
    }
    ll res = 0, cnt = 0;
    for (int i = 1; i <= scc_cnt; i ++){
        if (f[i] > res) res=  f[i], cnt = num[i];
        else if (f[i] == res) cnt = ((long long)cnt + num[i]) % mod;
    }
    cout << res << endl;
    cout << cnt % mod << endl;
    return 0;
}