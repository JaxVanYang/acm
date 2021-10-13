/* 
 * 第十二届蓝桥杯 C/C++ B组 E题 路径
 */

#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

const int maxn = 2077;
const int inf = 0x3f3f3f3f;
int graph[maxn][maxn], dist[maxn];
bool mark[maxn];
const int n = 2021;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void buildGraph() {
    memset(graph, 0x3f, sizeof(graph));
    for (int i = 1; i <= n; ++i) {
        for (int j = max(1, i - 21); j <= min(n, i + 21); ++j) {
            graph[i][j] = graph[j][i] = lcm(i, j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        graph[i][i] = 0;
    }
}

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 1; i < n; ++i) {
        int x = 0;
        for (int j = 1; j <= n; ++j) {
            if (!mark[j] && (x == 0 || dist[j] < dist[x])) {
                x = j;
            }
        }
        // cout << "x = " << x << endl;
        mark[x] = true;
        for (int y = 1; y <= n; ++y) {
            dist[y] = min(dist[y], dist[x] + graph[x][y]);
        }
    }
}

int main() {
    buildGraph();
    // cout << "edge = " << graph[15][25] << endl;
    dijkstra();
    cout << dist[n] << endl;
}