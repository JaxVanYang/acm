#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int head[N], ver[M], nex[M], edge[M], tot = 0;
bool mark[N], vis[N];

void add(int u, int v, int w) {
    ver[++tot] = v, edge[tot] = w;
    nex[tot] = head[u], head[u] = tot;
}

bool dfs(int u, int pre) {
    bool ret = false;
    for (int i = head[u]; i; i = nex[i]) {
        int v = ver[i];

        if (v != pre && dfs(v, u)) {
            ret = true;
        }
    }

    if (ret || mark[u]) {
        return true;
    }

    vis[u] = true;
    // cout << "u = " << u << endl;

    return false;
}

int calc(int u) {
    if (vis[u]) {
        return 0;
    }

    vis[u] = true;

    int ret = 1;

    for (int i = head[u]; i; i = nex[i]) {
        int v = ver[i];

        if (!vis[v]) {
            ret += calc(v);
        }
    }

    return ret;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i < n; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);

        add(u, v, w);
        add(v, u, w);
    }

    int num;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &num);

        mark[num] = true;
    }

    dfs(num, 0);

    int ans = calc(num);

    printf("%d\n", ans);
}