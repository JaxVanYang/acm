/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-10-19 20:03:14
 * @LastEditTime: 2021-10-19 20:41:19
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

const int N = 1e6 + 10, mod = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

int n, m, k;
int p[N];
int ans, res;
int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

struct edges{
    int a, b, c;
    bool operator< (const edges& m) const {
        return c < m.c;
    }
}e[N];

void solve(){
    cin >> n >> m >> k;

}

int main()
{
    int T;
    cin >> T;
    while (T --){
        solve();
    }
    return 0;
}
