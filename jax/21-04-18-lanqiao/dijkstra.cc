// E 题的邻接表写法


#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

const int maxn = 2077;
const int maxm = 50 * maxn;
int head[maxn], ver[maxm], edge[maxm], nex[maxm], d[maxn];
bool mark[maxn];
int n = 2021, m, tot;
priority_queue<pair<int, int>> pq;

void add(int x, int y, int z) {
    // 先加入新的后继结点和边权，再把这条边附加到 x 的头结点，然后更新头结点
    ver[++tot] = y, edge[tot] = z, nex[tot] = head[x], head[x] = tot;
}

int lcm(int a, int b) {
    return (ll)a * b / __gcd(a, b);
}

void dijkstra() {
    memset(d, 0x3f, sizeof(d));
    memset(mark, 0, sizeof(mark));
    d[1] = 0;
    pq.push(make_pair(0, 1));
    while (pq.size()) {
        int x = pq.top().second;
        pq.pop();
        if (mark[x]) continue;
        mark[x] = 1;
        for (int i = head[x]; i; i = nex[i]) {
            int y = ver[i], z = edge[i];
            if (d[x] + z < d[y]) {
                d[y] = d[x] + z;
                pq.push(make_pair(-d[y], y));
            }
        }
    }
}

int main() {
    for (int i = 1; i <= 2021; ++i) {
        for (int j = i + 1; j <= min(i + 21, 2021); ++j) {
            add(i, j, lcm(i, j));
        }
    }
    dijkstra();
    cout << d[n] << endl;
}