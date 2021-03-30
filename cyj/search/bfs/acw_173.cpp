/*
 * @Descripttion: 矩阵距离 多源bfs
 * @Topic link: https://www.acwing.com/problem/content/175/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-28 19:56:31
 * @LastEditTime: 2021-03-28 19:56:48
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1010;
typedef pair<int, int> PII;
char g[N][N];
int d[N][N];
int n, m;
queue<PII> q;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main(){
    
    cin >> n >> m;
    memset(d, -1, sizeof d);
    for (int i = 0; i < n; i ++){
        cin >> g[i];
        for (int j = 0; j < m; j ++){
            if (g[i][j] == '1'){
                d[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    while (q.size()){
        auto t = q.front();
        q.pop();
        
        for (int k = 0; k < 4; k ++){
            int x = t.first + dx[k], y = t.second + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1){
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j <m; j ++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}