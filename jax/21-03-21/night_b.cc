#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

const int maxn = 1005;

int a[maxn];

int main() {
    int n, k1, k2;
    scanf("%d%d%d", &n, &k1, &k2);
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) {
        int b;
        scanf("%d", &b);
        a[i] = abs(a[i] - b);
        pq.push(a[i]);
    }
    for (int i = 0; i < k1 + k2; ++i) {
        int top = pq.top();
        pq.pop();
        if (top == 0) {
            pq.push(1);
        } else {
            pq.push(top - 1);
        }
    }
    ll ans = 0;
    while (pq.size()) {
        ans += (ll)pq.top() * pq.top();
        pq.pop();
    }
    printf("%lld\n", ans);
}