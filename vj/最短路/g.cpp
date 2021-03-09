/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-06 17:35:22
 * @LastEditTime: 2021-03-09 15:01:18
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits.h>
#include <queue>
#include <vector>

#define x first
#define y second

using namespace std;

typedef long long LL;
const int N = 1e5 + 5, M = 2e5 + 5;
const LL INF = 1e17 + 10; 

typedef pair<LL, int> PLI;
int e[M], ne[M], b[M], h[N], idx;
LL dist[N];
LL w[M];
bool st[N];
int n, m ,T;

struct Node{
    int id;
    LL d;
    Node(int id, LL d):id(id),d(d){}
    bool operator < (const Node &A)const{
        return d > A.d;
    }
};

void add(int a, int y, LL c, int d){
    e[idx] = y, ne[idx] = h[a], w[idx] = c, b[idx] = d, h[a] = idx ++;
}

int dijkstra(){
    for (int i = 1; i <= n; i ++) dist[i] = INF;
    
    dist[1] = 1;
    priority_queue<Node> heap;
    
    heap.push(Node(1, 1));
    
    while (heap.size()){
        
        auto t = heap.top();
        heap.pop();
        int id = t.id;
        LL d = t.d;
        // cout << id << endl;
        if (id == n){
            // cout << "nnnn" << endl;
            for (int i = 0; ; i ++){
                // cout << dist[n] << endl;
                // cout << (1LL << i) << endl;
                if ((1LL << i) > d){
                    // cout << (1LL << i) << endl;
                    // cout << "mmmmmmm" << endl;
                    // cout << i - 1 << endl;
                    return i - 1;
                }
            }
        }
        
        if (st[id]) continue;
        st[id] = true;
        
        for (int i = h[id]; i != -1; i = ne[i]){
            int j = e[i];
            if (st[j]) continue;
            if (dist[j] > d + w[i] && ((d + w[i]) / d >= (1LL << b[i]))){
                dist[j] = d + w[i];
                heap.push(Node(j, dist[j]));
            }
        }
    }

    return -1;
}


int main(){
    scanf("%d", &T);
    while (T --){
        scanf("%d%d", &n, &m);
        // memset(h, -1, sizeof h);
        // memset(st, 0, sizeof st);
        for (int i = 0; i <= n; i ++) h[i] = -1;
        for (int i = 0; i <= n; i ++) st[i]  = 0;
        idx = 0;
        
        for (int i = 0; i < m ; i ++){
            int a, y, d;
            LL c;
            // cin >> a >> y >> c >> d;
            scanf("%d%d%lld%d", &a, &y, &c, &d);
            add(a, y, c, d);
        }
        // dijkstra();
        
        // cout << (1 << 31) << endl;
        // if (dist[n] == INF) cout << -1 << endl;
        // cout << "aaa" << endl;
        int res = dijkstra();
        printf("%d\n", res);
    }
    return 0;
}