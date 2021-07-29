/*
 * @Descripttion: 
 一个无向连通图最少加几条边变为一个边双连通分量
 * @Topic link: https://ac.nowcoder.com/acm/contest/963/A
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-19 20:01:29
 * @LastEditTime: 2021-07-19 20:02:41
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 5010, M = 2 * N;

int h[N], e[M], ne[M], idx;
int n, m;
int ecc_cnt, id[N], timestamp;
int dfn[N], low[N];
int stk[N], top;
int is_bridge[M], d[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void tarjan(int u, int from){
    dfn[u] = low[u] = ++ timestamp;
    stk[++ top] = u;
    for (int i = h[u];~i; i = ne[i]){
        int j = e[i];
        if (!dfn[j]){
            tarjan(j, i);
            low[u] = min(low[u], low[j]);
            if (low[j] > dfn[u]) is_bridge[i] = is_bridge[i^1] = 1;
        }
        else if (i != (from^1)) low[u] = min(low[u], dfn[j]);
    }
    
    if (low[u] == dfn[u]){
        int y;
        ++ ecc_cnt;
        do {
            y = stk[top --];
            id[y] = ecc_cnt;
        } while (y != u);
    }
}

int main(){
    cin >> n >> m;
    memset(h, - 1, sizeof h);
    for (int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b,a);
    }
    
    tarjan(1, -1);
    for (int i = 0; i < idx ;i ++){
        if (is_bridge[i]) d[id[e[i]]] ++;
    }
    int res = 0;
    for (int i = 1; i <= ecc_cnt; i ++){
        if (d[i] == 1) res ++;
    }
    cout << (res + 1) / 2 << endl;
    return 0;
}