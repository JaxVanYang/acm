#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 10005;
int n, m;
int fee[N];
int head[N], edge[2 * M], ver[2 * M], nex[2 * M], tot = 0;
int cost[N][105];

inline void add(int u, int v, int val) {
    ver[++tot] = v, edge[tot] = val;
    nex[tot] = head[u], head[u] = tot;
}

void solve() {
    int c, s, e;
    cin >> c >> s >> e;
    cost[s][0] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
    q.push({0, {s, 0}});
    while (q.size()) {
        auto [val, p] = q.top();
        q.pop();
        auto [city, fuel] = p;
        if (city == e) {
            cout << val << endl;
            return;
        }
        if (fuel < c && cost[city][fuel + 1] > val + 1) {
            cost[city][fuel + 1] = val + fee[city];
            q.push({val + fee[city], {city, fuel + 1}});
        }
        for (int i = head[city]; i; i = nex[i]) {
            int v = ver[i], w = edge[i];
            if (fuel >= w && cost[v][fuel - w] > val) {
                cost[v][fuel - w] = val;
                q.push({val, {v, fuel - w}});
            }
        }
    }
    cout << "impossible" << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> fee[i];

    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        add(u, v, d);
        add(v, u, d);
    }

    int q;
    cin >> q;
    while (q--) {
        memset(cost, 0x3f, sizeof cost);
        solve();
    }
}