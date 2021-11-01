/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-09-06 19:14:44
 * @LastEditTime: 2021-09-10 08:25:31
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

const int N = 110, M = 25, mod = 1e9 + 7;
typedef long long ll;
typedef pair<ll ,int> PII;
vector<int> all[N];
int n, m, k, num;
int h[M], e[M * M], ne[M * M], w[M * M], idx;
ll d[M];
ll dp[N], cost[N][N];
bool st[M], st1[M];

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

ll dijkstra(int x, int y){
    memset(st1, 0, sizeof st1);
    memset(st, 0, sizeof st);
    for (int i = x; i <= y; i ++){
        for (int j = 0; j < all[i].size(); j ++){
            st[all[i][j]] = 1;
        }
    }
    for (int i = 1; i < M; i ++) d[i] = 1e16;
    d[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while (q.size()){
        auto t = q.top();
        q.pop();
        ll dist = t.first, id = t.second;
        if (st1[id]) continue;
        st1[id] = 1;
        for (int i = h[id]; ~i; i = ne[i]){
            int j = e[i];
            if (st[j]) continue;
            if (d[j] > dist + w[i]){
                d[j] = dist + w[i];
                q.push({d[j], j});
            }
        }
    }
    return d[m];
}

int main()
{
    cin >> n >> m >> k >> num;
    memset(h, -1, sizeof h);
    for (int i = 0; i < num; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    int p;
    cin >> p;
    for (int i = 1; i <= p; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = b; j <= c; j ++){
            all[j].push_back(a);
        }
    }
    for (int i = 1; i <= n; i ++){
        for (int j = i; j <= n; j ++){
            cost[i][j] = dijkstra(i, j);
        }
    }
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i ++){
        dp[i] = cost[1][i] * i;
        for (int j = 1; j < i; j ++){   
            dp[i] = min(dp[i], dp[j] + cost[j+1][i] * (i-j) + k);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
