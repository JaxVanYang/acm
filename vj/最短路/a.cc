#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 300;
int a[maxn][maxn], d[maxn];
int n, m, s, t;
bool v[maxn];

void dijkstra() {
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[s] = 0;
    for (int i = 1; i < n; ++i) {
        int x = -1;
        for (int j = 0; j < n; ++j)
            if (!v[j] && (x == -1 || d[j] < d[x])) x = j;
        v[x] = 1;
        for (int y = 0; y < n; ++y)
            d[y] = min(d[y], d[x] + a[x][y]);
    }
}

int main() {
    while (cin >> n >> m) {
        memset(a, 0x3f, sizeof(a));
        for (int i = 0; i < n; ++i) a[i][i] = 0;
        for (int i = 0; i < m; ++i) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            a[x][y] = min(a[x][y], z);
            a[y][x] = a[x][y];
        }
        scanf("%d%d", &s, &t);
        dijkstra();
        if (d[t] == 0x3f3f3f3f) printf("-1\n");
        else printf("%d\n", d[t]);
    }
}