#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 1e5 + 5;
int n, m;
int s, t, k;
vector<pair<int, int>> edges[N], redges[N];
int dist[N];
bool st[N];
int vis[N];

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[t] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, t});
    while (q.size()) {
        auto [dis, cur] = q.top();
        q.pop();
        if (st[cur]) continue;
        st[cur] = 1;
        for (auto [v, w] : redges[cur]) {
            if (dist[v] > dis + w) {
                dist[v] = dis + w;
                q.push({dist[v], v});
            }
        }
    }
}

int solve() {
    if (s == t) ++k;    // 最短路至少有一条边
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({dist[s], s});
    while (q.size()) {
        auto [g, cur] = q.top();
        int dis = g - dist[cur];
        q.pop();
        ++vis[cur];
        if (vis[t] == k) {
            return dis;
        }

        for (auto [v, w] : edges[cur]) {
            if (vis[v] != k) q.push({dis + w + dist[v], v});
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        edges[a].push_back({b, l});
        redges[b].push_back({a, l});
    }
    cin >> s >> t >> k;
    dijkstra();
    // for (int i = 1; i <= n; ++i) {
    //     cout << dist[i] << ' ';
    // }
    // cout << endl;
    cout << solve() << endl;
}