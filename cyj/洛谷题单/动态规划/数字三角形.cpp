/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-10-13 19:26:59
 * @LastEditTime: 2021-10-13 19:30:12
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

const int N = 1010, mod = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

int g[N][N];
int dp[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= i; j ++){
            cin >> g[i][j];
        }
    }
    dp[1][1] = g[1][1];
    for (int i = 1; i < n; i ++){
        for (int j = 1; j <= i; j ++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + g[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + g[i+1][j+1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
