#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

const int N = 550;
int dist[N][N], opt[N], graph[N][N];
bool vis[N];
int n;
ll ans[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", dist[i] + j);
        }
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", opt + i);
    }

    for (int k = n - 1; k >= 0; --k) {
        int x = opt[k];
        vis[x] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][x] + dist[x][j]);
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) continue;
            for (int j = 1; j <= n; ++j) {
                if (!vis[j]) continue;
                ans[k] += dist[i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%lld ", ans[i]);
    }
    puts("");
}