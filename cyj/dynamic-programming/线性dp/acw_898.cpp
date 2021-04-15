/*
 * @Descripttion: 数字三角形
 * @Topic link: https://www.acwing.com/problem/content/description/900/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-09 09:37:28
 * @LastEditTime: 2021-04-09 09:38:48
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 10010;

int e[N][N], f[N][N];
int n;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= i; j ++){
            cin >> e[i][j];
        }
    }
    
    // 因为各点权值为-1000~1000,所以需要初始化为比-1000小的数
    for (int i = 0; i <= n; i ++){
        for (int j = 0; j <= i + 1; j ++){
            f[i][j] = -0x3f3f3f3f;
        }
    }
    
    f[1][1] = e[1][1];
    for (int i = 2; i <= n; i ++){
        for (int j = 1; j <= i; j ++){
            f[i][j] = e[i][j] + max(f[i-1][j], f[i-1][j-1]);
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i ++) ans = max(ans, f[n][i]);
    cout << ans << endl;
    
    return 0;
}
