/*
 * @Descripttion: 
     此题最小割不等同于网络流最小割，此题可以包含点集内部的边，由01分数规划，我们要求最小值，当内部边小于0时我们必选
     直接在判定时将res加上w-mid， 再从剩下的所有大于0的边中选尽量少的边，从s集合到t集合中的边我们必选，由最大流与最
     小割定理，我们所求即为最小割值，集合内部大于0的边我们必不再选
 * @Topic link: https://www.acwing.com/problem/content/2281/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-17 14:17:15
 * @LastEditTime: 2021-09-16 15:00:08
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110, M = 810;
const double eps = 1e-8, INF = 1e8;
int n, m ,S ,T;
int q[N], cur[N], d[N];
int h[N], e[M], w[M], ne[M], idx;
double f[M];

void add(int a,int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
    e[idx] = a, ne[idx] = h[b], w[idx] = c, h[b] = idx ++;
}

bool bfs(){
    int hh= 0, tt = 0;
    memset(d, -1, sizeof d);
    d[S] = 0, cur[S] = h[S], q[0] = S;
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (d[j] == -1 && f[i]){
                d[j] = d[t] + 1;
                cur[j] = h[j];
                if (j == T) return true;
                q[++ tt]  =j;
            }
        }
    }
    return false;
}

double find(int x, double limit){
    if (x == T) return limit;
    double flow = 0;
    for (int i = cur[x]; ~i && flow < limit; i = ne[i]){
        int j = e[i];
        cur[x] = i;
        if (d[j] == d[x] + 1 && f[i]){
            double t = find(j, min(limit -flow, f[i]));
            if (!t) d[j] = -1;
            else {
                f[i] -= t, f[i^1] += t, flow += t;
            }
        }
    }
    return flow;
}

double dinic(double mid){
    memset(f, 0, sizeof f);
    double res = 0;
    for (int i = 0; i < idx; i += 2){
        if (w[i] < mid) res += w[i] - mid;
        else {
            f[i] = f[i^1] = w[i] - mid;
        }
    }
    double flow;
    while (bfs()){
        while (flow = find(S, INF)) res += flow;
    }
    return res;
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d%d%d", &n, &m, &S, &T);
    for (int i = 0; i < m; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    double l = 1, r = 1e7;
    while (r - l > eps){
        double mid = (l + r) / 2;
        if (dinic(mid) <= 0) r = mid;
        else l = mid;
    }
    printf("%.2f", l);
    return 0;
}