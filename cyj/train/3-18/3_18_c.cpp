/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-18 20:05:53
 * @LastEditTime: 2021-03-18 20:13:32
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;

int p[N], pr[N], tmp[N], d[N];
int n, k, m;
map<string, int> mp;
string s[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> k >> m;
    for (int i = 0; i <= n;  i++) p[i] = i;
    for (int i = 1; i <= n ; i++) cin >> s[i], mp[s[i]] = i;
    for (int i = 1; i <= n; i ++) cin >> pr[i], d[i] = pr[i];
    for (int i = 0; i < k; i ++){
        int x;
        cin >> x;
        for (int i = 0; i < x; i ++){
            cin >> tmp[i];
        }
        for (int i = 0; i < x - 1; i ++){
            int pa = find(tmp[i]), pb = find(tmp[i + 1]);
            p[pa] = pb;
            d[pb] = min(d[pb], d[pa]);
        }
    }
    LL res = 0;
    for (int i = 0; i < m; i ++){
        string t;
        cin >> t;
        int pt = find(mp[t]);
        res += d[pt];
    }
    cout << res << endl;
    return 0;
}
