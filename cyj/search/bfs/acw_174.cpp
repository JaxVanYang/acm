/*
 * @Descripttion: 推箱子
 * @Topic link: https://www.acwing.com/problem/content/176/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-03-29 18:07:33
 * @LastEditTime: 2021-03-29 21:20:30
 */
 
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define x first
#define y second

using namespace std;

const int N = 22;
typedef pair<int, int> PII;

struct st{
    int x, y, dir;
};

char g[N][N]; // 储存地图
vector<int> path[N][N][4]; // path[j][k][i] 表示人从推(j,k,i)的上一个状态的位置，走到推(j,k,i)这个状态的位置的行走路径
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool vis[N][N][4], used[N][N]; // BFS的判重数组，为了防止BFS遍历相同状态
st pre[N][N][4];  // 表示箱子在(x, y)，且是由上个位置向i方向推得来的，即上一个状态是(x - dx[i], y - dy[i])
int pr[N][N]; // 储存人从哪个方向走过来的，即是人上个位置为(x - dx[i], y - dy[i])
PII dist[N][N][4]; //dist[j][k][i]是表示从初始状态到达j,k,i状态所需要的箱子最短路程和人行走最短路程
int n, m;

bool check(int x, int y){
    return x > 0 && x <= n && y > 0 && y <= m && g[x][y] != '#';
}

int bfs_man(PII s, PII end, PII node, vector<int> &seq){
    memset(pr, -1, sizeof pr);
    memset(used, 0, sizeof used);
    
    queue<PII> q;
    used[node.x][node.y] = used[s.x][s.y] = 1;
    q.push(s);
    while (q.size()){
        auto t = q.front();
        q.pop();
        
        if (t == end){
            seq.clear();
            while (pr[t.x][t.y] != -1){
                seq.push_back(pr[t.x][t.y]);
                int dir = pr[t.x][t.y]; // // 用变量保存一下，t.x后面发生了改变，再变化t.y时会出错
                t.x -= dx[dir], t.y -= dy[dir];
            }
            return seq.size();
        }
        
        for (int i = 0; i < 4; i ++){
            int a = t.x + dx[i], b = t.y + dy[i];
            if (check(a, b) && !used[a][b]){
                used[a][b] = 1;
                pr[a][b] = i;
                q.push({a, b});
            }
        }
    }
    
    return -1;
}

bool bfs_box(PII box, st &end, PII man){
    queue<st> q;
    memset(vis, 0, sizeof vis);
    PII ans = {1e7, 1e7};
    bool succees = false;
    for (int i = 0; i < 4; i ++){
        int a = box.x + dx[i], b = box.y + dy[i];
        int j = box.x - dx[i], k = box.y - dy[i];
        vector<int> seq;
        if (check(a, b) && check(j, k) && bfs_man(man, {j, k}, box, seq) != -1){
            q.push({a, b, i});
            vis[a][b][i] = 1;
            pre[a][b][i] = {box.x, box.y, -1};
            dist[a][b][i] = {1, seq.size()};
            path[a][b][i] = seq;
        }
    }
    
    while (q.size()){
        auto t = q.front();
        q.pop();
        
        if (g[t.x][t.y] == 'T'){
            succees = true;
            if (dist[t.x][t.y][t.dir] < ans){
                ans = dist[t.x][t.y][t.dir];
                end = t;
            }
        }
        
        for (int i = 0; i < 4; i ++){
            int a = t.x + dx[i], b = t.y + dy[i];
            int j = t.x - dx[i], k = t.y - dy[i];
            vector<int> seq;
            if (check(a, b) && check(j, k)){
                int d = bfs_man({t.x - dx[t.dir], t.y - dy[t.dir]}, {j, k}, {t.x, t.y}, seq);
                if (d != -1 && !vis[a][b][i]){
                    vis[a][b][i] = 1;
                    auto &d = dist[t.x][t.y][t.dir];
                    dist[a][b][i] = {d.x + 1, d.y + seq.size()};
                    q.push({a, b, i});
                    path[a][b][i] = seq;
                    pre[a][b][i] = t;
                }
            }
        }
    }
    return succees;
}

int main(){
    int cn = 1;
    while (cin >> n >> m, n || m){
        printf("Maze #%d\n", cn ++);
        for (int i = 1; i <= n;  i++) cin >> (g[i] + 1);
        PII man, box;
        st end;
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= m; j ++){
                if (g[i][j] == 'S') man = {i, j};
                else if (g[i][j] == 'B') box = {i, j};
            }
        }
        
        if (!bfs_box(box, end, man)) puts("Impossible.");
        else {
            char op[] = "nswe";
            string res;
            while (~end.dir){
                res += op[end.dir] - 32;
                for (auto t : path[end.x][end.y][end.dir]) res += op[t];
                end = pre[end.x][end.y][end.dir];
            }
            reverse(res.begin(), res.end());
            cout << res << endl;
        }
        puts("");
    }
    
    return 0;
}
