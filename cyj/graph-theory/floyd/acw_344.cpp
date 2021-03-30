/*
 * @Descripttion: floyd求最小环
 * @Topic link: https://www.acwing.com/problem/content/description/346/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-03-28 15:23:02
 * @LastEditTime: 2021-03-28 15:29:03
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
typedef long long LL;

int n, m;
int d[N][N], g[N][N], pre[N][N];
int ans = INF;
vector<int> path;

void push(int i, int j){
    if (i == j){
        path.push_back(i); // 如果到了起点，将起点加入并返回
        return;
    }
    path.push_back(j);
    push(i, pre[i][j]);
}

void print(){
    for (int i = 1; i <= n; i ++){
        for (int j = 1;  j<= n; j ++){
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    memset(pre, 0, sizeof pre);
    for (int i = 1; i <= n; i ++) g[i][i] = 0; // floyd初始化准备
    
    for (int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c); // 可能有重边
        g[b][a] = g[a][b];
        pre[a][b] = a, pre[b][a] = b; // pre数组的初始化
    }
    memcpy(d, g, sizeof d);
    for (int k = 1; k <= n; k ++){
        
        for (int i = 1; i < k; i ++){
            for (int j = i + 1; j < k; j ++){ // i， j， k需为三个不同的点，k为环中节点编号最大的点
                if ((LL)d[i][j] + g[i][k] + g[k][j] < ans){ // g[a][b]初始化为INF，三者相加可能爆int
                    ans = d[i][j] + g[i][k] + g[k][j];
                    path.clear();
                    path.push_back(k); // 先加入k，再加入d[i][j]路径上的节点
                    push(j, i); // 递归实现加点
                }
            }
        }
        
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= n; j ++){
                if (d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    pre[i][j] = pre[k][j]; // floyd记录路径，定义为从i到j的最短路径上j的前驱
                }
            }
        }
    }
    
    // print(); 调试代码
    if (ans == INF){
        puts("No solution.");
        return 0;
    }
    for (auto t : path) cout << t << ' ';
    
    return 0;
}