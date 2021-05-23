#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 105;
int g[maxn][maxn];

int main() {
    int n, m, s;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v]++;
        g[v][u]++;
    }
}