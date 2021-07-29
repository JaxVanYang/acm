/*
 * @Descripttion: 
 * @Topic link: https://vjudge.net/contest/429156#problem
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-23 19:33:32
 * @LastEditTime: 2021-03-24 09:11:16
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

const int N = 110, M = 1010, mod = 1e9 + 7;
int d[N];
typedef long long LL;
typedef pair<int, int> PII;

int n ,m, s;
bool vis[N][N];
vector<int> e[N];
int point[N], cnt;
int in[N];
int ans;

void dfs(int u, int fa){
    if (cnt == s){ 
        ans ++;
        return;
    }
    if (in[u] < s - 1){ // 度少于s-1直接返回
        return;
    }
    
    for (auto item : e[u]){ // 遍历边，判断出点能否dfs
        bool flag = 1;
        if (item == fa) continue;
        for (int i = 0; i < cnt; i ++){ // 如果已在集合中的点到此点没有边，则不是完全图，不能dfs
            if (vis[point[i]][item] == false) {
                flag = 0;
                break;
            }
        }
        if (flag){
            point[cnt ++] = item;
            dfs(item, u);
            cnt --; // 记得恢复现场
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T --){
        memset(vis, 0, sizeof vis);
        memset(in, 0, sizeof in);
        memset(point, 0, sizeof point);
        for (int i = 1; i <= n; i ++) e[i].clear();
        cin >> n >> m >> s;
        for (int i = 0; i < m; i ++){
            int a , b;
            cin >> a >> b;
            e[a].push_back(b); // 记录各点的边,只存储有向边
            in[a] ++, in[b] ++;
            vis[a][b] = vis[b][a] = 1;
        }
        ans = 0;
        for (int i = 1; i <= n; i ++){
            cnt = 0; // 注意每次初始化为0，或写入dfs函数中使之成为局部变量
            point[cnt ++] = i; // point存储当前连通块中的点
            dfs(i, -1);
        }
        cout << ans << endl;
    }
    return 0;
}
