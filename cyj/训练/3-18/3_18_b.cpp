/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-18 19:58:48
 * @LastEditTime: 2021-03-18 20:00:37
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int N = 1010, mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;

int c[N], ans = 0x3f3f3f3f;
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++){
        int t;
        cin >> t;
        c[t] ++;
    }

    for (int i = 1 ; i <= n ; i++){
        ans = min(ans, c[i]);
    }
    cout << ans << endl;
    return 0;
}
