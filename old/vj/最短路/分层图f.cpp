/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-09 14:56:47
 * @LastEditTime: 2021-03-12 16:55:35
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 2000, M = 10000;

int h[N], ne[M], e[M], w[M], idx;
int dist[N];
int pre[N];
bool st[N];
int n, S, T, m, k;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void dijkstra(int S, int T){
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    
    dist[S] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size()){
        auto t = heap.top();
        heap.pop();

        int id = t.y, d = t.x;

        if (st[id]) continue;
        st[id] = true;

        for (int i = h[id]; i != -1; i = ne[i]){
            int j = e[i];
            if (dist[j] > dist[id] + w[i]){
                dist[j] = dist[id] + w[i];
                pre[j] = id;
                heap.push({dist[j], j});
            }
        }
    }
}

int main(){

    int P = 0;
    ios::sync_with_stdio(false);
    while (cin >> n >> S >> T){
        if (P ++) cout << endl;
        memset(h, -1, sizeof h);
        cin >> m;
        idx = 0;
        for (int i = 0; i < m; i ++){
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c), add(b, a, c), add(a + n, b + n, c), add(b + n,a + n, c);
        }

        cin >> k;
        for (int i = 0; i < k; i ++){
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b + n, c);
            add(b, a + n, c);
        }
        
        dijkstra(S, T);

        vector<int> path;
        int res = min(dist[T], dist[T + n]);
        int last = res == dist[T] ? T : T + n, use = 0;
        while (last != 0){
            int t = last, t2 = pre[last];
            if (last > n) path.push_back(last - n);
            else path.push_back(last);
            // cout << t - n << " " << t2 - n << endl;
            // if (((t - n) ^ (t2 - n)) < 0) use = t2;
            if ((t > n && t2 <= n)) use = t2;
            // cout << use << endl;
            last = pre[last];
            // cout << "last " << t << " pre[last] " << t2 << endl;
        }
        while (path.size()){
            int t = path.back();
            if (path.size() == 1){
                cout << t << endl;
                break;
            }
            cout << t << " ";
            path.pop_back();
        }
        if (!use) cout << "Ticket Not Used" << endl;
        else cout << use << endl;
        
        cout << res << endl;
    }

    return 0;
}