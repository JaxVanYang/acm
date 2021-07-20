/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-19 19:58:44
 * @LastEditTime: 2021-07-19 19:58:45
 */

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e4 + 10, M = 2e5 + 10;

int h[N], e[M], ne[M], idx;
int n, m;
int dfn[N], low[N], timestamp;
int root, ans, num;

void add(int a, int b){
    e[idx] = b, ne[idx] =  h[a], h[a]  = idx ++;
}

void tarjan(int u){
    dfn[u] =  low[u]  = ++ timestamp;
    int cnt = 0;
    for (int i  = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (!dfn[j]){
            tarjan(j);
            low[u] = min(low[j], low[u]);
            if (low[j] >= dfn[u]){
                cnt ++;
            }
        }
        else low[u] = min(low[u], dfn[j]);
    }
    if (u != root && cnt > 0) cnt ++;
    ans = max(ans, cnt);
}

int main(){
    
    while (cin >> n >> m, n || m){
        idx = root = ans = num = 0;
        memset(h, -1, sizeof h);
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        
        for (int i = 0; i < m; i ++){
            int a, b;
            cin >> a >> b;
            add(a, b), add(b, a);
        }
        for ( root =  0; root < n; root ++){
            if (!dfn[root]){
                tarjan(root);
                num ++;
            }
        }
        cout << ans + num - 1 <<  endl;
    }
    
    return 0;
}