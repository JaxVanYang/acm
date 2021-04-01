#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn];
int x[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", a + i, b + i, c + i);
        // ans += c;
    }
    
    // priority_queue<pair<ll, pair<int, int>>> pq;
    priority_queue<pair<ll, int>> pq;
    for (int i = 0; i < n; ++i) {
        // pq.push(make_pair(-a[i] - b[i], make_pair(i, 2)));
        pq.push(make_pair(-a[i] - b[i], i));
    }
    for (int i = 0; i < m; ++i) {
        int idx = pq.top().second;
        pq.pop();
        x[idx]++;
        ll val = 2 * a[idx] * (x[idx] + 1) - a[idx] + b[idx];
        pq.push(make_pair(-val, idx));
    }
    // for (int i = 0; i < n; ++i) cout << "i = " << i << " x = " << x[i] << endl;
    for (int i = 0; i < n; ++i) {
        // 永远记得处理溢出
        ans += (ll)a[i] * x[i] * x[i] + b[i] * x[i] + c[i];
    }
    printf("%lld", ans);
}