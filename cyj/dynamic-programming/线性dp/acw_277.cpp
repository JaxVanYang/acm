/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-15 18:58:12
 * @LastEditTime: 2021-04-21 15:03:56
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int N = 33, M = 5010;
int s[N], a[N][M], b[N][M];
PII g[N];
int f[N][M];
int ans[N];

void print(int n, int m){
    if (n == 0) return;
    print(a[n][m], b[n][m]); // 注意此处状态转移时边的含义
    if (a[n][m] == n){
        // 1到n饼干数均加以
        for (int i = 1; i <= n; i ++) ans[g[i].y] += 1; 
    }else {
        // 从k+1到n饼干数都为一
        for (int i = a[n][m] + 1; i <= n; i ++) ans[g[i].y] = 1;
    }
    
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> g[i].x, g[i].y = i;
    sort(g+1, g + 1 +n);
    reverse(g+1, g+1+n); // 以贪婪度从大到小排序，贪婪度大的孩子分更多的苹果
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; i ++){
        s[i] = s[i-1] + g[i].x;
        for (int j = i; j <= m; j ++){
            f[i][j] = f[i][j-i]; 
            a[i][j] = i;
            b[i][j] = j - i;
            for (int k = 0; k < i; k ++){
                if (f[k][j-(i-k)] + (s[i] - s[k]) * k < f[i][j]){
                    f[i][j] = f[k][j-(i-k)] + (s[i]-s[k]) * k;
                    a[i][j] = k;
                    b[i][j] = j-(i-k);
                }
            }
        }
    }
    
    cout << f[n][m] << endl;
    print(n, m);
    for (int i = 1; i <= n; i ++) cout << ans[i] << ' ';

    return 0;
}