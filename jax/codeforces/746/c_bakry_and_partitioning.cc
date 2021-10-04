#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int head[M], nex[M], ver[M], tot = 0;
int a[N], sum[N];
int val, last;

inline void add(int u, int v) {
    ver[++tot] = v;
    nex[tot] = head[u], head[u] = tot;
}

void reset(int n) {
    fill(ver, ver + tot + 1, 0);
    fill(head, head + n + 1, 0);
    fill(nex, nex + n + 1, 0);
    tot = 0;
}

int dfs(int u, int pre) {
    sum[u] = a[u];

    for (int i = head[u]; i; i = nex[i]) {
        int v = ver[i];

        if (v != pre) {
            sum[u] ^= dfs(v, u);
        }
    }

    return sum[u];
}

void find(int u, int pre) {
    if (sum[u] == val) {
        last = u;
    }

    for (int i = head[u]; i; i = nex[i]) {
        int v = ver[i];

        if (v != pre) {
            find(v, u);
        }
    }
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);

    reset(n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);

        add(u, v);
        add(v, u);
    }

    val = dfs(1, 0);
    // cout << "val = " << val << endl;

    if (val == 0) {
        puts("YES");
        return;
    }

    if (k < 3) {
        puts("NO");
        return;
    }

    find(1, 0);
    // cout << "last = " << last << endl;

    if (last == 1) {
        puts("NO");
        return;
    }

    for (int i = head[last]; i; i = nex[i]) {
        int u = ver[i];

        for (int j = head[u]; j; j = nex[j]) {
            int &v = ver[j];

            if (v == last) {
                v = ver[nex[j]];
                nex[j] = nex[nex[j]];
                continue;
            }
        }
    }

    dfs(1, 0);

    last = -1;
    find(1, 0);

    if (last == -1) {
        puts("NO");
    } else {
        puts("YES");
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }
}