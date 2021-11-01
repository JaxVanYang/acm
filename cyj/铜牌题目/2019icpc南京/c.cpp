/*
 * @Descripttion: 
 * @Topic link: https://nanti.jisuanke.com/t/42397
 * @Question meaning: 
 * @Status: Time Limit Exceeded, 中间存在许多重复路径，
 *  想到每次从四周没有刚好少一的点开始bfs以及转移条件，考虑拓扑排序转移状态
 * @Author: cyj
 * @Date: 2021-10-24 20:58:56
 * @LastEditTime: 2021-10-24 21:35:34
 */

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1010, mod = 1e9 + 7, M = 2e7;
typedef pair<int, int> PII;
int g[N][N];
int ans, n, m;
vector<PII> s;
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
struct node {
    int x, y, tim;
}q[30000000];

void bfs(PII p){
    int hh = 0, tt = 1;
    q[0] = {p.first, p.second, 1};
    while (hh != tt){
        auto t = q[hh ++];
        if (hh == M) hh = 0;
        int x = t.x, y = t.y, tim = t.tim;
        bool f = 0;
        for (int k = 0; k < 4; k ++){
            int x1 = x + dx[k], y1 = y + dy[k];
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m){
                if (g[x1][y1] == g[x][y] + 1){
                    q[tt ++] = {x1, y1, tim + 1};
                    if (tt == M) tt = 0;
                    f = 1;
                }
            }
        }
        if (!f && tim >= 4) ans = (ans + 1) % mod;
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i<= n; i ++){
        for (int j =1; j <= m; j ++){
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j ++){
            bool f = 0;
            for (int k = 0; k < 4; k ++){
                int x = i + dx[k], y = j + dy[k];
                if (x >= 1 && x <= n && y >= 1 && y <= m){
                    if (g[x][y] == g[i][j] - 1) f = 1;
                }
            }
            if (!f) s.push_back({i, j});
        }
    }
    for (int i = 0; i < s.size(); i ++){
        bfs(s[i]);
    }
    cout << ans << endl;

    return 0;
}