/*
 * @Descripttion: 装满的油箱 拆点
 * @Topic link: https://www.acwing.com/problem/content/description/178/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-03-30 21:00:07
 * @LastEditTime: 2021-03-30 21:06:26
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1010, C = 110, M = 20010;

int n, m;
int dist[N][C];
bool st[N][C];
int pr[N];
int ne[M], e[M], h[N], w[M], idx;

struct point{
    int d, id, c;
    bool operator< (const point & m) const { // 重载小于号，创建大根堆时等同于创建小根堆，记得加末尾的const
        return d > m.d;
    }
};

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int dijkstra(int C, int S, int T){
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    
    dist[S][0] = 0;
    priority_queue<point> heap;
    heap.push({0, S, 0});
    while (heap.size()){
        auto t = heap.top();
        heap.pop();
        if (t.id == T){
            return t.d;
        }
        int id = t.id, d = t.d, c = t.c;
        // cout << d << " " << id << " " << c << endl;
        if (st[id][c]) continue;
        st[id][c] = 1;
        
        if (c < C && (dist[id][c + 1] > d + pr[id])){ // 如果邮箱未满，可以更新c+1，并将其入队
            dist[id][c + 1] = d + pr[id];
            heap.push({dist[id][c + 1], id, c + 1});
        }
        for (int i = h[id]; i != -1; i = ne[i]){ // 遍历出边，如果可以到达下个节点，且可以更新距离，更新并入队
            int j = e[i];
            if (c >= w[i] && (dist[j][c - w[i]] > d)){
                dist[j][c-w[i]] = d;
                heap.push({dist[j][c-w[i]], j, c - w[i]});
            }
        }
    }
    
    return -1;
}

int main(){
    
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n; i ++) scanf("%d", &pr[i]);
    for (int i = 0; i < m; i ++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    int q;
    scanf("%d", &q);
    while (q --){
        int C, S, T;
        scanf("%d%d%d", &C, &S, &T);
        int ans = dijkstra(C, S, T);
        if (ans == -1) puts("impossible");
        else printf("%d\n", ans);
    }
    return 0;
}