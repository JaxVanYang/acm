/*
 * @Descripttion: 噩梦
 * @Topic link: https://www.acwing.com/problem/content/179/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-03-31 16:13:53
 * @LastEditTime: 2021-03-31 16:22:35
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
const int N = 810;
int n, m, cnt;
char g[N][N];
PII by, gl, gt[2]; // 存储男孩，女孩以及鬼（两个）的初始位置
int st[N][N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

bool check(int x, int y, int t){
    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == 'X') return false;
    for (int i = 0; i < 2;  i++){
        int a = abs(gt[i].x - x), b = abs(gt[i].y - y);
        if (a + b <= 2 * t) return false;
    }
    return true;
}

bool bfs(queue<PII> &q, int u, int s, int tm){
    // 正在处理的队列，更新轮数， st为1（男）还是2（女）， 进行的总轮数（决定了鬼的捕捉范围）
    for (int i = 0; i < u; i ++){
        for (int j = 0, len = q.size(); j < len; j ++){ // 此处用len保存每次更新的次数，q.size()一直在变化
            auto t = q.front();
            q.pop();
            // 鬼更新完捕捉范围后人才可以移动，所以需要先验证位置是否合法
            if (!check(t.x, t.y, tm)) continue; // 如果队头已经在鬼范围内，一直continue
            for (int k = 0; k < 4; k ++){
                int a = t.x + dx[k], b = t.y + dy[k];
                if (!check(a, b, tm)) continue; // 如果坐标合法且不在鬼的范围内
                if (!st[a][b]){
                    st[a][b] = s;
                    q.push({a, b});
                }
                else if (st[a][b] == (s ^ 3)) return true; // 如果st存在且不同于s，表示二者已经相会

            }
        }
    }
    
    return false;
}

int bfs(){
    queue<PII> qa, qb;
    memset(st, 0, sizeof st);
    qa.push(by), qb.push(gl);
    st[by.x][by.y] = 1, st[gl.x][gl.y] = 2; // 初始化
    int tm = 1; // 进行的总轮数
    while (qa.size() || qb.size()){ // 只要有一个队列不为空，就继续
        if (bfs(qa, 3, 1, tm) || bfs(qb, 1, 2, tm)) return tm; 
        tm ++;
    }
    
    return -1;
}

int main(){
    int T;
    cin >> T;
    while (T --){
        cin >> n >> m;
        cnt = 0;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                cin >> g[i][j];
                if (g[i][j] == 'M') by = {i, j};
                else if (g[i][j] == 'G') gl = {i, j};
                else if (g[i][j] == 'Z') gt[cnt ++] = {i, j};
            }
        }
        
        int ans = bfs();
        cout << ans << endl;
    }
    
    return 0;
}