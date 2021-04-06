/*
 * @Descripttion: 电路维修 只包含01边权的最短路，双端队列bfs
 * @Topic link: https://www.acwing.com/problem/content/177/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-03-30 21:54:13
 * @LastEditTime: 2021-03-30 22:06:16
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 510;

char g[N][N];
int dist[N][N];
bool st[N][N]; // 距离数组更新时仅代表第一次入队，一个点有可能被更新入队多次，
               // 第一次出队时为其最小值，所以需要st数组记录
int n, m;
int T;
int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1}; // 点的转移
int gx[] = {-1, -1, 0, 0}, gy[] = {-1, 0, 0, -1}; // 对应的转移的g中符号所在位置
char c[] = "\\/\\/";

int bfs(){
    
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    
    dist[0][0] = 0;
    deque<PII> q;
    q.push_front({0, 0});
    
    while (q.size()){
        auto t = q.front();
        q.pop_front();
        
        if (t.x == n && t.y == m){ // 第一次搜到结果即为最小值，返回
            return dist[n][m];
        }
        
        if (st[t.x][t.y]) continue; // 每个状态第一次出队时即为最小值，之后再出队便不需要再管
        st[t.x][t.y] = 1;
        
        for (int i = 0; i < 4;  i ++){
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x > n || y < 0 || y > m) continue; // 判断边界
            int w = (g[t.x + gx[i]][t.y + gy[i]] != c[i]); // 如果与g中相同边权为0，否则为1
            if (dist[x][y] > dist[t.x][t.y] + w){ // 如果可以更新
                dist[x][y] = dist[t.x][t.y] + w;
                if (w) q.push_back({x, y}); // 若边权为1，加入队尾，否则加入队头
                else q.push_front({x, y});
            }
        }
    }
    return -1;
}

int main(){
    
    cin >> T;
    while (T --){
        cin >> n >> m;
        for (int i = 0; i < n; i ++) cin >> g[i];
        if (n + m & 1) puts("NO SOLUTION");
        else cout << bfs() << endl;
    }
    
    return 0;
}