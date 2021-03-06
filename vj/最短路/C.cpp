/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-05 11:07:50
 * @LastEditTime: 2021-03-06 10:23:52
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>


#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 1005;

int g[N][N];
int dist[N];
int pre[N];
bool st[N];
int n, m;

void dijkstra(int type){
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int ver = t.y, dis = t.x;
        
        if (st[ver]) continue;
        st[ver] = true;
        
        for (int i = 1; i <= n; i ++){
            if (dist[i] > dis + g[ver][i]){
                dist[i] = dis + g[ver][i];
                heap.push({dist[i], i});
                if (type)pre[i] = ver;
            }
        }
        
    }
}

int main(){
    
    while (scanf("%d%d", &n, &m) != EOF){
        memset(g, 0x3f, sizeof g);
        
        while (m --){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            g[a][b] = min(g[a][b], c);
            g[b][a] = min(g[b][a], c);
        }
        
        dijkstra(1);
        
        int j = n, res = -0x3f3f3f3f;
        
        // for (int i = 1; i<= n; i ++) cout << dist[i] << " ";
        // cout << endl;
        // for (int i = 1; i<= n; i ++) cout << pre[i] << " ";
        // cout << endl;
        while (pre[j]){
            int t = g[j][pre[j]];
            // cout << "pre[j] " << pre[j] << endl;
            g[j][pre[j]] = 0x3f3f3f3f;
            g[pre[j]][j] = 0x3f3f3f3f;
            
            dijkstra(0);
            // printf("j %d pre[j] %d dist[n] %d\n", j, pre[j], dist[n]);
            res = max(res, dist[n]);
            g[j][pre[j]] = t;
            g[pre[j]][j] = t;
            
            // cout << "j " << j << endl;
            j = pre[j];
        }
        
        printf("%d\n", res);
    }
    
    return 0;
}