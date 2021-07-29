/*
 * @Descripttion: 最长公共子序列
 * @Topic link: https://www.acwing.com/problem/content/899/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-09 09:39:28
 * @LastEditTime: 2021-04-09 09:39:47
 */

#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
string a, b;
int f[N][N];

int main(){
    
    cin >> n >> m >> a >> b;
    
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m ; j ++){
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if (a[i-1] == b[j-1]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
        }
    }
    
    cout << f[n][m] << endl;
    
    return 0;
}