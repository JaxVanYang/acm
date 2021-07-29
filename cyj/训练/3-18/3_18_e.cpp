/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-18 20:49:00
 * @LastEditTime: 2021-03-18 21:13:46
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int N = 55, mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;

char g[N][N];
int tmp[N], cnt;
bool ru[N], cu[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;  i++){
        for (int j = 1;  j <= m; j ++){
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i ++){
        cnt = 0;
        for (int j = 1 ;j <= m;  j ++){
            if (g[i][j] == '#') tmp[cnt ++] = j;
        }
        for (int j = 1; j <= n; j ++){
            for (int k = 0; k < cnt - 1; k ++){
                if (g[j][tmp[k]] != g[j][tmp[k + 1]]){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
