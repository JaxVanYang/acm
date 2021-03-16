/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-15 09:32:35
 * @LastEditTime: 2021-03-15 11:41:53
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 1e3 + 2, mod = 1e9 + 7;


typedef pair<int, int> PII; 
int n, m, k, S, T;
typedef unsigned long long ULL;
const ULL INF = 1e60;

ULL dp[M][M];
int e[N], ne[N], h[N], w[N], idx;
PII q[N];
ULL dist[N];
bool st[N];

void add(int a, int b, int c, int d){

    e[idx] = b, ne[idx] = h[a], w[idx] = dp[c][d], h[a] = idx ++;
    
}

void dijkstra(int beg, int S, int T){
    memset(st, 0, sizeof st);
    for (int i = 1; i <= n; i ++) dist[i] = INF;
    dist[S] = beg;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({beg, S});
    while (heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int id = t.second;
        if (st[id]) continue;
        st[id] = true;
        
        for (int i = h[id]; ~i; i = ne[i]){
            int j = e[i];
            // cout << w[i] << endl;
            if (dist[j] > (dist[id] * w[i])){
                dist[j] = (dist[id] * w[i]) % mod;
                heap.push({dist[j], j});
            }
        }
    }
}

int main(){
    for (int i = 0; i < M; i++){
        for (int j = 0; j <= i; j ++){
            if (!j) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]);
        }
    }
    // ULL ma = 0;
    // for (int i = 0 ; i < M; i ++) ma = max(ma, dp[1000][i]);
    // cout << ma << endl;
    int T1;
    scanf("%d", &T1);
    while (T1 --){
        memset(h, -1, sizeof h);
        idx = 0;
        scanf("%d%d%d%d%d", &n, &m, &k, &S, &T);
        for (int i = 0; i < m; i ++){
            int u, v, a, b;
            scanf("%d%d%d%d", &u, &v, &a, &b);
            add(u, v, a, b);
        }
        
        dijkstra(k, S, T);
        
        if (dist[T] == INF) printf("-1\n");
        else printf("%lld\n", dist[T] % mod);
    }
    
    return 0;
}