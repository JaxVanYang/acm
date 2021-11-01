/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-08-28 13:10:53
 * @LastEditTime: 2021-08-28 19:34:52
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

const int N = 210, mod = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

int g[N][N];
bool st[N][N];

struct node {
    int pow;
}a[N][N];
int dp[500];

int main()
{
    // int T;
    // cin >> T;
    // while (T --){
        int tot = 0;
        memset(dp, 0, sizeof dp);
        memset(a, 0, sizeof a);
        memset(g, 0, sizeof g);
        memset(st, 0, sizeof st);
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j ++){
                int t;
                char c;
                cin >> t >> c;
                g[i][j] = t, st[i][j] = c == 'Y'?1:0;
            }
        }
        for (int i = 1; i <= m; i ++){
            int t = 0;
            bool f = 0;
            for (int j = n; j; j --){
                if (!f) t += 1;
                if (f) a[i][t].pow += g[j][i];
                else a[i][t].pow = a[i][t-1].pow + g[j][i];
                f = 0;
                if (st[j][i]) f = 1;
                if (j == 1 && f == 1) a[i][t-1] = a[i][t];
            }
        }
        for (int i = 1; i <= m; i ++){
            for (int j = k; j >= 0; j --){
                for (int x = 0; x <= 202; x ++){
                    if (x && !a[i][x].pow) break;
                    if (j >= x) {
                        dp[j] = max(dp[j], dp[j-x] + a[i][x].pow);
                    }
                }
            }
        }
        cout << dp[k] << endl;
    // }
    
    return 0;
}
