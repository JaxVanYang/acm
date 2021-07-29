/*
 * @Descripttion: 立体推箱子
 * @Topic link: https://www.acwing.com/problem/content/174/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-03-28 19:27:48
 * @LastEditTime: 2021-03-28 19:36:35
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>


using namespace std;

struct point{
    int x, y, st;
};

const int N = 505;
// 预先处理在各状态下向各方向滚动的位移数组，此处需要细心，保存的是位移前后两个代表点的坐标差
int next_x[3][4] = {{0, 0, -2, 1}, {0, 0, -1, 1}, {0, 0, -1, 2}};
int next_y[3][4] = {{-2, 1, 0, 0}, {-1, 2, 0, 0}, {-1, 1, 0, 0}};
int next_st[3][4] = {{1, 1, 2, 2}, {0, 0, 1, 1}, {2, 2, 0, 0}};
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int d[N][N][3]; // 储存各点的最小步数
point pre[N][N][3]; // 调试代码时使用的前驱数组
char g[N][N];
point S, T; // 起点与终点
queue<point> q;
int n, m;

bool valid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void find_S_T(){ // 找到起点与终点并将g中改为'.'
    S = T = {0, 0, 0};
    for (int i = 0; i < n;  i++){
        for (int j = 0; j < m; j ++){
            if (g[i][j] == 'O'){
                T = {i, j, 0};
                g[i][j] = '.';
                break;
            }
        }
    }
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            if (g[i][j] == 'X'){
                for (int k = 0; k < 4; k ++){
                    int x = dx[k] + i, y = dy[k] + j;
                    if (valid(x, y) && g[x][y] == 'X'){
                        // 我们使用横躺的左边点与竖躺的上边点表示这个状态
                        // 所以坐标均为两个x，y的较小值
                        S.x = min(i, x), S.y = min(j, y); 
                        S.st = k < 2 ? 1 : 2;
                        g[i][j] = g[x][y] = '.'; // 改为硬地
                        break;
                    }
                }
                if (!S.st) S = {i, j, 0}, g[i][j] = '.'; // 如果起点只有一个
            }
        }
    }
}

bool valid(point t){ // 判断一个状态是否合法
    if (!valid(t.x, t. y)) return 0;
    if (g[t.x][t.y] == '#') return 0;
    if (t.st == 0)
        if (g[t.x][t.y] == 'E') return 0;
    if (t.st == 1){
        if (!valid(t.x, t.y + 1) || g[t.x][t.y + 1] == '#') return 0;
    }
    if (t.st == 2){
        if (!valid(t.x + 1, t.y) || g[t.x + 1][t.y] == '#') return 0;
    }
    return 1;
}

int bfs(){
    q.push(S);
    d[S.x][S.y][S.st] = 0;
    while (q.size()){
        auto t = q.front();
        q.pop();
        if (t.x == T.x && t.y == T.y && t.st == T.st){ // 找到终点，返回距离
           return d[t.x][t.y][t.st];
        }      
        int a = t.x, b = t.y, s =t.st;
        for (int k = 0; k < 4; k ++){
            int x = a + next_x[s][k], y = b + next_y[s][k], st = next_st[s][k];
            point tmp = {x, y, st};
            if (valid(tmp)){ 
                if (d[x][y][st] == -1){ // 尚未访问过
                    d[x][y][st] = d[a][b][s] + 1;
                    // pre[x][y][st] = {a, b, s}; 调试代码，记录前驱
                    q.push(tmp);
                }
            }
        }
    }
    return -1; // 无解
}

int main(){
    
    while (cin >> n >> m, n || m){
        while (q.size()) q.pop();
        memset(d, -1, sizeof d);
        memset(g, 0, sizeof g);
        for (int i = 0; i < n; i ++){
            cin >> g[i];
        }
        find_S_T();
        // pre[S.x][S.y][S.st] = {-1, 0, 0}; 调试代码
        int ans = bfs();
        
        // point &m = pre[T.x][T.y][T.st]; // 调试代码，输出前驱
        // while (m.x != -1){
        //     cout << m.x + 1 <<" " <<  m.y +1<< " " <<m.st << endl;
        //     m = pre[m.x][m.y][m.st];
        // }
        
        if (ans == -1) cout << "Impossible\n";
        else cout << ans << endl;
    }
    
    return 0;
}