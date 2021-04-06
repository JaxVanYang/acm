/*
 * @Descripttion: 通信线路
 *  解法一： 分层图最短路 （参考博客https://blog.csdn.net/sugarbliss/article/details/86551050）
 *  解法二： 二分+双端队列bfs acw_340_2.cpp
 * @Topic link: https://www.acwing.com/problem/content/description/342/
 * @Question meaning: 在一个正常的图上可以进行 k 次决策，对于每次决策，不影响图的结构，
 * 只影响目前的状态或代价。一般将决策前的状态和决策后的状态之间连接一条权值为决策代价的边，
 * 表示付出该代价后就可以转换状态了
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-06 14:24:48
 * @LastEditTime: 2021-04-06 20:47:43
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
const int N = 1010, M = 2e4 + 10; // 由于建k+1层图需要开1e7级别的数组，为了防止爆空间，
                                  // 使用多开一维数组记录信息的方式做分层图

bool st[N][N]; 
int dist[N][N];
int h[N], e[M], ne[M], w[M], idx;
int n, m, K;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void dijkstra(int s){
    memset(dist, 0x3f, sizeof dist);
    dist[s][0] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});
    
    while (heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int d = t.x, id = t.y % n, use = t.y / n; // id记录是哪一个点，use记录在第几层
        if (st[id][use]) continue;
        st[id][use] = 1;
        
        for (int i = h[id]; ~i; i = ne[i]){
            int j = e[i];
            if (dist[j][use] > max(d, w[i])){ // 更新同层点
                dist[j][use] = max(d, w[i]);
                heap.push({dist[j][use], n * use + j});
            }
            if (use < K && dist[j][use + 1] > dist[id][use]){ // 更新下一层
                dist[j][use + 1] = dist[id][use]; 
                heap.push({dist[j][use + 1], n * (use + 1) + j});
            }
        }
    }
}

int main(){
    cin >> n >> m >> K;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a - 1, b - 1, c), add(b - 1, a - 1, c);
    }
    
    dijkstra(0);
    
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= K; i ++) ans = min(ans, dist[n - 1][i]); 
    /**
    * 遍历每层图的终点记录最小值，防止使用边数小于K
    * 另外一种解决办法是在每层图的终点向下一层图的终点建一条权值为0的边
    */
   
    if (ans == 0x3f3f3f3f) puts("-1");
    else cout << ans << endl;
    
    return 0;
}
