/*
 * @Descripttion: 最优贸易 解法一
 *  解法一：tarjan求强连通分量 + 缩点 + 拓扑序dp
 *  解法二：两遍spfa，正图反图各一遍，dp思想在有环图上的最短路做法
 *  解法三：最短路上跑spfa求最长路
 * @Topic link: https://www.acwing.com/problem/content/description/343/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-06 18:31:23
 * @LastEditTime: 2021-06-04 21:26:22
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 3e6 + 10;

int n, m;
int pr[N];
int h[N], hs[N], e[M], ne[M], idx; // h为原图表头，hs为缩点后的表头
int id[N], scc_cnt;
int id_min[N], id_max[N]; // 存储每个强连通分量中点权的最大值与最小值
int dfn[N], low[N], timestamp;
bool in_stk[N];
int stk[N], top;
int f[N], mincost[N]; // f为dp数组，记录从1到i的收益最大值，mincost记录从1到i的点权最小值

void add(int h[], int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void tarjan(int s){
    dfn[s] = low[s] = ++ timestamp;
    stk[++ top] = s, in_stk[s] = 1;
    for (int i = h[s]; ~i; i = ne[i]){
        int j = e[i];
        if (!dfn[j]){
            tarjan(j);
            low[s] = min(low[s], low[j]);
        }
        else if (in_stk[j]) low[s] = min(low[s], dfn[j]);
    }
    
    if (dfn[s] == low[s]){
        int y;
        scc_cnt ++;
        do {
            y = stk[top --];
            id[y] = scc_cnt;
            id_min[scc_cnt] = min(id_min[scc_cnt], pr[y]); 
            id_max[scc_cnt] = max(id_max[scc_cnt], pr[y]);
            in_stk[y] = false;
        } while (y != s);
    }
}

int main(){
    
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i <= n; i ++) id_min[i] = 300, mincost[i] = 300;
    for (int i = 1; i <= n; i ++) scanf("%d", &pr[i]);
    memset(hs, -1, sizeof hs);
    for (int i = 0; i < m; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(h, a, b);
        if (c == 2) add(h, b, a);
    }
    
    for (int i = 1; i <= n; i ++){
        if (!dfn[i]) tarjan(i);
    }
    
    for (int i = 1; i <= n; i ++){ // 缩点，建图
        for (int j = h[i]; ~j; j = ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if (a != b){
                add(hs, a, b);
            }
        }
    }
    f[scc_cnt] = id_max[scc_cnt] - id_min[scc_cnt]; // 为dp做初始化（f数组与mincost数组）
    mincost[scc_cnt] = id_min[scc_cnt];
    for (int i = scc_cnt; i; i --){
        for (int j = hs[i]; ~j; j = ne[j]){
            int k = e[j];
            mincost[k] = min(mincost[i], id_min[k]);
            f[k] = max(max(f[i], f[k]), id_max[k] - mincost[k]);
        }
    }
    
    printf("%d", f[1]);
    
    return 0;
}