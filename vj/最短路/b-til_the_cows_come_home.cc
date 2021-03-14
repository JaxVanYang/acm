#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 1005;
int a[maxn][maxn], d[maxn];
bool v[maxn];
int t, n;

int main() {
    scanf("%d%d", &t, &n);
    memset(a, 0x3f, sizeof(a));
    memset(v, 0, sizeof(v));
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= n; ++i) a[i][i] = 0;
    // v[n] = 1;
    d[n] = 0;
    for (int i = 0; i < t; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x][y] = min(a[x][y], z);
        a[y][x] = a[x][y];
    }
    for (int i = 1; i < n; ++i) {
        int x = -1;
        for (int j = 1; j <= n; ++j) {
            if (!v[j] && (x == -1 || d[j] < d[x])) x = j;
        }
        v[x] = 1;
        for (int y = 1; y <= n; ++y) d[y] = min(d[y], d[x] + a[x][y]);
    }
    printf("%d\n", d[1]);
}