/*
 * @Descripttion: 道路与航线 
 * @Topic link: https://www.acwing.com/problem/content/description/344/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-07 21:33:30
 * @LastEditTime: 2021-04-07 21:33:57
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
const int N = 25010, M = 2e5, INF = 0x3f3f3f3f;

int h[N], e[M], ne[M], w[M], idx;
int n, m, p, s;
int cnt, id[N];
vector<int> point[N];
int dist[N], in[N];
bool st[N];
queue<int> tq;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void dfs(int u, int c){
    id[u] = c, point[c].push_back(u);
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (!id[j]){
            dfs(j, c);
        }
    }
}

void dijkstra(int u){
    priority_queue<PII, vector<PII>, greater<PII>> q;
    for (auto t : point[u]) q.push({dist[t], t});
    
    while (q.size()){
        auto t = q.top();
        q.pop();
        
        int d = t.x, ver = t.y;
        if (st[ver]) continue;
        st[ver] = 1;
        
        for (int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            int a = id[ver], b = id[j];
            if (dist[j] > d + w[i]){
                dist[j] = d + w[i];
                if (a == b){
                    q.push({dist[j], j});
                }
            }
            if (a != b && -- in[b] == 0) tq.push(b);
        }
    }
}

void topsort(int s){
    memset(dist, 0x3f, sizeof dist);
    
    dist[s] = 0;
    for (int i = 1; i <= cnt; i ++){
        if (!in[i]) tq.push(i);
    }
    
    while (tq.size()){
        int t = tq.front();
        tq.pop();
        dijkstra(t);
    }
}

int main(){
    
    memset(h, -1, sizeof h);
    scanf("%d%d%d%d", &n, &m, &p, &s);
    for (int i = 0; i < m; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    for (int i = 1; i <= n; i ++){
        if (!id[i]) dfs(i, ++ cnt);
    }
    
    for (int i = 0; i < p; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        in[id[b]] ++;
        add(a, b, c);
    }
    
    topsort(s);
    
    for (int i = 1; i <= n; i ++){
        if (dist[i] >= INF / 2) puts("NO PATH");
        else printf("%d\n", dist[i]);
    }
    
    return 0;
}