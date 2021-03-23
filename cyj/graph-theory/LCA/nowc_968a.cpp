/*
 * @Descripttion: tarjan离线算法求最近公共祖先，距离为两点深度-2*LCA深度
 * @Topic link: https://ac.nowcoder.com/acm/contest/968/A
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-22 10:42:49
 * @LastEditTime: 2021-03-22 11:47:41
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 5, M = N  * 2;
typedef pair<int, int> PII;
int e[M], ne[M], h[N], w[M], idx;
vector<PII> query[N]; // first存查询的另外一个点，second存查询编号
int res[N];
int dist[N], st[N], p[N];
int n, m;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa){
    for (int i = h[u];~i; i = ne[i]){
        int j = e[i];
        if (j != fa){
            dist[j] = dist[u] + 1;
            dfs(j, u);
        }
    }
}

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void tarjan(int u){
    st[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (!st[j]){
            tarjan(j);
            p[j] = u; 
        }
    }
    for (auto item : query[u]){
        int id = item.second, y = item.first;
        if (st[y] == 2){
            int py = find(y);
            res[id] = dist[u] + dist[y] - 2 * dist[py]; 
        }
    }
    st[u] = 2;
}

int main(){
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i ++){
        int a ,b;
        scanf("%d%d", &a, &b);
        if (a != b){
            query[a].push_back({b, i});
            query[b].push_back({a, i});
        }
    }
    for (int i = 1;  i<= n; i ++) p[i] = i;
    dfs(1, -1);
    tarjan(1);
    for (int i = 0; i < m; i ++) printf("%d\n", res[i]);
    
    
    return 0;
}