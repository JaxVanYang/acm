/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-20 14:07:37
 * @LastEditTime: 2021-07-20 21:14:13
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

const int N = 2e3 + 10;
typedef long long LL;
typedef pair<int, int> PII;
int row[N], g[N][N], t[N][N];
int n, m;
int s[N], tt, w[N], ans;

int main()
{
    int T;
    scanf("%d", &T);
    while (T --){
        ans = 0;
        memset(w, 0, sizeof w);
        memset(row, 0, sizeof row);
        memset(s, 0, sizeof s);
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= m; j ++){
                scanf("%d", &g[i][j]);
                if (g[i][j] >= g[i-1][j]) t[i][j] = 1;
                else t[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= m; j ++){
                if (t[i][j]) row[j] += 1;
                else row[j] = 1;
            }
            tt = row[m + 1] = 0;
            for (int i = 1; i <= m + 1; i ++){
                if (!tt || s[tt] < row[i]){
                    s[++ tt] = row[i];
                    w[tt] = 1;
                }
                else {
                    int width = 0;
                    while (tt && s[tt] >= row[i]){
                        width += w[tt];
                        ans = max(ans, width * s[tt --]);
                    }
                    s[++ tt] = row[i];
                    w[tt] = width + 1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

// for (int i = 0 ;i < n; i++){
//     if (!tt || s[tt] < row[i]){
//         s[++ tt] = row[i];
//         w[tt] = 1;
//     }
//     else {
//         int width = 0;
//         while (tt && s[tt] >= row[i]){
//             width += w[tt];
//             ans = max(ans, widtth * s[tt --]);
//         }
//         s[++ tt] = row[i];
//         w[tt] = 1 + width;
//     }
// }
