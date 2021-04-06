/*
 * @Descripttion: 通信线路 解法2 二分 + 双端队列bfs
 * @Topic link: https://www.acwing.com/problem/content/342/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-06 15:05:57
 * @LastEditTime: 2021-04-06 20:08:47
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 1010, M = 2e4 + 10;

bool st[N]; 
int dist[N];
int h[N], e[M], ne[M], w[M], idx;
int n, m, K;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

bool bfs(int sd){
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[1] = 0;
    deque<int> q;
    q.push_front(1);
    
    while (q.size()){
        auto t = q.front();
        q.pop_front();
        
        if (t == n) break;
        
        if (st[t]) continue;
        st[t] = true;
        
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            int cost = w[i] > sd ? 1 : 0;
            if (dist[j] > dist[t] + cost){
                dist[j] = dist[t] + cost;
                if (cost) q.push_back(j);
                else q.push_front(j);
            }
        }
    }
    
    return dist[n] <= K;
}


int main(){
    cin >> n >> m >> K;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    int l = 0, r = 1e6 + 1; // l = 0时k大于实际需要使用边数
    while (l < r){
        int mid = l + r >> 1;
        if (bfs(mid)) r = mid;
        else l = mid + 1;
    }
   if (l == 1e6 + 1) puts("-1");
   else cout << l << endl;
    
    return 0;
}
