/*
 * @Descripttion: 最优贸易 解法二 两遍spfa
 * @Topic link: https://www.acwing.com/problem/content/description/343/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-06 20:07:51
 * @LastEditTime: 2021-04-07 12:12:46
 */

/**
 * 先求出：

从 1 走到 i 的过程中，买入水晶球的最低价格 d[i]
从 i 走到 n 的过程中，卖出水晶球的最高价格 f[i]
然后枚举每个城市作为买卖的中间城市，求出 dmax[i] - dmin[i] 的最大值即可。

求 dmin[i] 和 dmax[i] 时，由于不是拓扑图，状态的更新可能存在环，因此不能使用动态规划，
只能使用求最短路的方式。
另外，我们考虑能否使用 dijkstra 算法，如果当前 dmin[i] 最小的点是 5，
那么有可能存在边 5-> 6, 6-> 7, 7-> 5，假设当前 dmin[5] = 10，则有可能存在 6 的价格是11，
但 7 的价格是3，那么 dmin[5] 的值就应该被更新成3，
仔细想想其实7->5的单向边类似于形成了负环，与340分层图中可以使用dijkstra不同，340中为无向图
所以放在无向图中5就 可以更新7
因此当前最小值也不一定是最终最小值，所以dijkstra算法并不适用，我们只能采用 spfa 算法。

时间复杂度
瓶颈是SPFA，SPFA 算法的时间复杂度是 O(km)，其中 k 一般情况下是个很小的常数，
最坏情况下是 n, n 表示总点数，m 表示总边数。因此总时间复杂度是 O(km)
*/

#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

const int N = 2e5 + 10,  M = 1e6 + 10;

int h[N], e[M], ne[M], w[M], idx;
int pr[N];
int d[N], f[N]; // f[x]表示从x到n（从反图上为从n到x）的所有路径中，
                // 能够经过的去权值最大的节点的权值
bool st[N];
int n, m;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void spfa(int flag, int S, int dist[]){
    memset(st, 0 ,sizeof st);
    dist[S] = pr[S];
    int q[N];
    int hh = 0, tt = 0;
    q[tt ++] = S, st[S] = 1;
    
    while (hh != tt){
        int t = q[hh ++];
        if (hh == N) hh = 0;
        st[t] = false;
        
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (w[i] == 2 || w[i] == flag){
                // val记录待更新值，注意此更新方式不满足dijkstra的贪心性质
                int val = flag == 1 ? min(dist[t], pr[j]) : max(dist[t], pr[j]);
                if (flag == 1 && dist[j] > val || flag == -1 && dist[j] < val){
                    dist[j] = val;
                    if (!st[j]){
                        q[tt ++ ] = j;
                        if (tt == N) tt = 0;
                        st[j] = 1;
                    }
                }
            }
        }
    }
}

int main(){
    
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 1;  i<= n;  i++) scanf("%d", &pr[i]);
    for (int i = 0; i < m; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c == 1 ? -1 : c); // 为单向边时给反图建边
    }
    memset(d, 0x3f, sizeof d);
    spfa(1, 1, d);
    memset(f, -0x3f, sizeof f); // 类似求最长路，初始化为 -0x3f3f3f3f
    spfa(-1, n, f);
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        ans = max(ans, f[i] - d[i]); 
    }
    
    printf("%d", ans);
    
    return 0;
}
