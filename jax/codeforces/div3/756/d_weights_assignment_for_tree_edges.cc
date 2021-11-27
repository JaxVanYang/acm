#include <iostream>
#include <cstring>

const int N = 2e5 + 10;
int b[N], p[N], dist[N], ans[N];

void solve() {
    int n;
    scanf("%d", &n);
    memset(dist + 1, 0xff, sizeof(dist[1]) * n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", b + i);
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", p + i);
    }

    dist[p[1]] = 0;
    ans[p[1]] = 0;
    int pre = 0;

    for (int i = 2; i <= n; ++i) {
        int u = p[i], fa = b[u];
        if (dist[fa] == -1) {
            puts("-1");
            return;
        }
        ans[u] = pre + 1 - dist[fa];
        pre = dist[u] = ans[u] + dist[fa];
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}