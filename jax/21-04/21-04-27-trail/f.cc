/* 
 * 不要粗心统计错误的值，需要统计的是差值，而不是边权
 */

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
int id[maxn];
int find(int p) {
    if (id[p] != p) {
        id[p] = find(id[p]);
    }
    return id[p];
}

struct Node{
    int u, v, w;
    bool operator<(const Node &node) {
        return w > node.w;
    }
} edges[maxn];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        id[i] = i;
    }
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    sort(edges, edges + m);
    // queue<int> q;
    stack<int> stk;
    int p = 0;
    init(n);
    for (int i = 1; i < n; ++i) {
        while (find(edges[p].u) == find(edges[p].v)) ++p;
        stk.push(p);
        id[find(edges[p].u)] = find(edges[p].v);
    }
    // cout << "good" << endl;
    ll ans = 0;
    
    if (edges[stk.top()].w <= k) {
        while (stk.size() && edges[stk.top()].w < k) {
            ans += k - edges[stk.top()].w;
            stk.pop();
        }
    } else {
        ans = INT32_MAX;
        for (int i = 0; i < m; ++i) {
            ans = min(ans, abs(k - (ll)edges[i].w));
        }
    }
    printf("%lld\n", ans);
}