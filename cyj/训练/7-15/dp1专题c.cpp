/*
 * @Descripttion: 树的重心
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-15 22:24:47
 * @LastEditTime: 2021-07-15 22:56:02
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

const int N = 1e4 + 10, M = 2 * N, mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;

int h[N], e[M], ne[M], idx;
int num[N], size[N];
bool st[N];
int n;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa){
    size[u] = 1;
    for (int i = h[u]; ~i; i =ne[i]){
        int j = e[i];
        if (j == fa) continue;
        dfs(j, u);
        size[u] += size[j];
        num[u] = max(num[u], size[j]);
    }
    num[u] = max(num[u], n - size[u]);
    if (num[u] <= n / 2) st[u] = 1;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
        st[b] = 1;
    }
    memset(st, 0, sizeof st);
    dfs(1, -1);
    for (int i = 1; i <= n; i ++) if (st[i]) cout << i << endl;

    return 0;
}
