/*
 * @Descripttion: 移动服务
 * @Topic link: https://www.acwing.com/problem/content/description/276/
 * @Question meaning: 
 * 刚开始想法是f[i, a, b, c]，复杂度1000 * 200 * 200 * 200超时
 * 由题意可知每次转移后必有一个点在p[i]处，于是可除去一个维度的冗余信息，降低复杂度
 * 状态表示为处理了前i个请求，且此时三个点分别在在j, k, p[i] 处时的最小花费
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-12 18:34:13
 * @LastEditTime: 2021-04-12 18:41:24
 */

#include <iostream>
#include <cstring>
#include <cstring>

using namespace std;

const int N = 210;

int f[N * 5][N][N], p[N * 5];
int n, m;
int w[N][N];

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> w[i][j];
        }
    }
    memset(f, 0x3f, sizeof f);
    f[0][1][2] = 0; // 初始化时认为a,b分别在1，2处，c在3处
    p[0] = 3;
    for (int i = 1; i <= m; i ++){
        cin >> p[i];
        for (int j = 1; j <= n; j ++){
            for (int k = 1; k <= n; k ++){
                if (f[i-1][j][k] != 0x3f3f3f3f){ // 如果合法
                    if (j != p[i] && p[i] != k){ // 因为不能有两个服务员位置重叠，判断不移动的两点是否合法
                        f[i][j][k] = min(f[i][j][k], f[i-1][j][k] + w[p[i-1]][p[i]]);
                    }
                    if (p[i-1] != p[i] && k != p[i]){ // 判断合法
                        f[i][p[i-1]][k] = min(f[i][p[i-1]][k], f[i-1][j][k] + w[j][p[i]]);
                    }
                    if (p[i-1] != p[i] && j != p[i]){ // 判断合法
                        f[i][j][p[i-1]] = min(f[i][j][p[i-1]], f[i-1][j][k] + w[k][p[i]]);
                    }
                }
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            ans = min(ans, f[m][i][j]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}