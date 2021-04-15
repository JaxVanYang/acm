/*
 * @Descripttion: 最优贸易 解法三：分层图最短路上跑spfa求最长路
 * @Topic link: https://www.acwing.com/problem/content/description/343/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-06 21:16:03
 * @LastEditTime: 2021-04-06 21:32:53
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
const int N = (1e5 + 5) * 3, M = 3e6 + 10;

int h[N], e[M], ne[M], pr[N], w[N], idx;
int dist[N][3];
bool st[N][3];
int n, m;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void spfa(int s){
    memset(dist, -0x3f, sizeof dist); // 求最长路，初始化为-0x3f3f3f3f
    dist[s][0] = 0;
    queue<PII> q;
    q.push({0, s}), st[s][0] = 1;
    while (q.size()){
        auto t = q.front();
        q.pop();
        
        int d = t.x, id = t.y % n, use = t.y / n; // id为点编号，use为所在层数
        st[id][use] = false;
        
        for (int i = h[id]; ~i; i = ne[i]){
            int j = e[i];
            if (dist[j][use] < d){
                dist[j][use] = d;
                if (!st[j][use]){
                    q.push({dist[j][use], n * use + j});
                    st[j][use] = true;
                }
            }
            if (use < 2){ // 如果可以向下一层扩展
                int wt = use == 0 ? -w[i] : w[i]; // 第一次决策为花钱买入，第二次决策为卖出
                if (dist[j][use + 1] < d + wt){
                    dist[j][use + 1] = d + wt;
                    if (!st[j][use + 1]){
                        q.push({dist[j][use + 1], (use + 1) * n  + j});
                        st[j][use + 1] = true;
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n; i ++) cin >> pr[i];
    for (int i = 0; i < m ; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a --, b --;
        add(a, b, pr[a]);
        if (c == 2) add(b, a, pr[b]);
    }
    
    spfa(0);
    
    int ans = 0;
    // 其实求max(dist[n-1][0], dist[n-1][2]就行了，dist[n-1][1]买入不卖出必亏的)
    for (int i = 0; i < 3; i ++) ans = max(ans, dist[n-1][i]);
    printf("%d", ans);
    return 0;
}
