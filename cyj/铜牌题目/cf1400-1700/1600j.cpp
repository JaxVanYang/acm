/*
 * @Descripttion: 水题，求各连通块大小
 * @Topic link: https://codeforces.ml/problemset/problem/1600/J
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-10-26 21:04:19
 * @LastEditTime: 2021-10-26 21:13:42
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1e3 + 10;
int g[N][N];
bool st[N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int n, m;

int dfs(int x, int y){
    int ans = 1;
    st[x][y] = 1;
    for (int i = 0; i < 4; i ++){
        int x1 = x + dx[i], y1 = y + dy[i];
        if (!(g[x][y] >> i & 1 ) && x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && !st[x1][y1]){
            st[x1][y1] = 1;
            int t = dfs(x1, y1);
            ans += t;
        }
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for (int i = 1;  i<= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> g[i][j];
        }
    }
    vector<int> res;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (!st[i][j]){
                int size = dfs(i, j);
                res.push_back(size);
            }
        }
    }
    sort(res.begin(), res.end());
    for (int i = res.size()-1; i >= 0; i --){
        cout << res[i] << ' ';
    }

    return 0;
}