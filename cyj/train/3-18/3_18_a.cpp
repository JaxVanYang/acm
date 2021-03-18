/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-18 19:36:27
 * @LastEditTime: 2021-03-18 20:23:42
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[N], b[N], c[N], d[N], e[N], s[N], s1[N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i-1] + a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    for (int i = 1; i <= n; i ++) c[i] = b[i] ? a[i] : 0;
    for (int i = 1; i <= n; i ++) s1[i] = s1[i-1] + c[i];
    for (int i = k; i <= n; i ++){
        d[i] = s[i] - s[i-k];
    }
    for (int i = k; i <= n; i ++){
        e[i] = s1[i] - s1[i-k];
    }
    int res = 0, ans = 0;
    for (int i = k; i <= n; i ++){
        int t = d[i] - e[i];
        if (t > res) res = t, ans = i;
    }
    // cout << ans << endl;
    cout << s1[n] + (d[ans] - e[ans]) << endl;
    return 0;
}
