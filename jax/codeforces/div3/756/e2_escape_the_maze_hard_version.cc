#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

const int N = 2e5 + 10, M = N << 1;
int head[N], next[M], ver[M], tot = 0, dis[N], fa[N];
bool fri[N], vis[N], leaf[N];
int n, k, ans;
std::vector<int> fris;

inline void add(int u, int v) {
    ver[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
    fris.clear();
}

void reset() {
    tot = 0;
    memset(head + 1, 0, sizeof(head[1]) * n);
    memset(fri + 1, 0, sizeof(fri[1]) * n);
    memset(dis + 1, 0x3f, sizeof(dis[1]) * n);
    memset(vis + 1, 0, sizeof(vis[1]) * n);
}

void bfs() {
    std::queue<int> q;
    q.push(1);
    fa[1] = 0, vis[1] = true;
    while (q.size()) {
        int u = q.front(); q.pop();
        bool flag = true;
        for (int i = head[u]; i; i = next[i]) {
            int v = ver[i];
            if (vis[v]) continue;
            vis[v] = true;
            if (fri[v]) fris.push_back(v);
            fa[v] = u;
            q.push(v);
            flag = false;
        }
        leaf[u] = flag;
    }
}

void dfs(int u, int d) {
    if (!u) return;
    if (!u || dis[u] <= d) return;
    dis[u] = d;
    // std::cout << "u = " << u << " d = " << d << " dis = " << dis[u] << std::endl;
    dfs(fa[u], d + 1);
}

bool check(int u, int d) {
    if (dis[u] < d) {
        ++ans;
        return false;
    }
    if (dis[u] == d) {
        if (leaf[u]) return true;
        ++ans;
        return false;
    }
    if (leaf[u]) return true;
    // std::cout << "u = " << u << " d = " << d << " dis = " << dis[u] << std::endl;
    for (int i = head[u]; i; i = next[i]) {
        int v = ver[i];
        if (vis[v]) continue;
        vis[v] = true;
        if (check(v, d + 1)) return true;
    }
    return false;
}

void solve() {
    ans = 0;
    scanf("%d%d", &n, &k);
    reset();
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        fri[x] = true;
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }

    bfs();

    for (int u : fris) dfs(u, 0);

    memset(vis + 1, 0, sizeof(vis[1]) * n);
    vis[1] = true;
    if (check(1, 0)) puts("-1");
    else printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}