#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int inf = 0x3f3f3f3f;
vector<pair<int, int>> edges[N];
inline void add(int u, int v, int w) {
    edges[u].push_back({v, w});
}
int n, p, k;
bool vis[N];
int dis[N];

bool check(int ans) {
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    deque<int> dq;
    dq.push_back(1);
    while (dq.size()) {
        int cur = dq.front();
        dq.pop_front();
        if (vis[cur]) continue;
        vis[cur] = 1;
        if (cur == n) return dis[cur] <= k;

        for (auto [v, w] : edges[cur]) {
            int val = w > ans;
            dis[v] = min(dis[v], dis[cur] + val);
            if (val) dq.push_back(v);
            else dq.push_front(v);
        }
    }
    return false;
}

int main() {
    int max_l = -1;
    cin >> n >> p >> k;
    for (int i = 0; i < p; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        add(a, b, l);
        add(b, a, l);
        max_l = max(max_l, l);
    }

    int l = 0, r = max_l + 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (l > max_l) {
        cout << -1 << endl;
    } else {
        cout << l << endl;
    }
}