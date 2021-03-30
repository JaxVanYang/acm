/*
 * @Descripttion: 
 * @Topic link: https://vjudge.net/contest/429156#problem/D
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-23 21:13:25
 * @LastEditTime: 2021-03-24 23:29:38
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 55;
int g[N][N];
int n, m;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main(){

    int T;
    cin >> T;
    while (T --){
        cin >> n >> m;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                cin >> g[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (g[i][j]) res += 1; // 如果高度不为0，加上顶上面积1
                for (int k = 0; k < 4; k ++){
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= m){ // 出界则说明此面面积无阻挡
                        res += g[i][j];
                        continue;
                    }
                    if (g[i][j] > g[x][y]) res += g[i][j] - g[x][y];
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}