/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-17 20:29:19
 * @LastEditTime: 2021-03-17 20:51:52
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int N = 110, P = 131;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

ULL p[N], h[N];
int n;
int dp[N][2];

ULL get(int l, int r){
    return h[r] - h[l - 1] * p[r - l  + 1];
}

int main()
{
    p[0] = 1;
    cin >> n;
    char a[N];
    cin >> a + 1;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i ++){
        h[i] = h[i-1] * P + (a[i] - 'a' + 1);
        p[i] = P * p[i-1];
    }   
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i ++){
        dp[i][0] = min(dp[i][0], dp[i-1][0] + 1);
        dp[i][1] = min(dp[i][1], dp[i-1][1] + 1);
        // cout << dp[i][0] << endl;
        if ((i-1) * 2 <= n && get(1, i - 1) == get(i, 2 * i - 2)){
            // cout << i << endl;
            // cout << "nn" << endl;
            dp[2 * i - 2][1] = min(dp[i-1][0] + 1, dp[2 * i - 2][1]);
        }      
    }
    int res = min(dp[n][0], dp[n][1]);
    cout << res << endl;
    return 0;
}
