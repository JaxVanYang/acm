#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> using Heap = priority_queue<T, vector<T>, greater<T>>;

const int N = 5005;
const ll INF = INT64_MAX / 2;

int x[N], y[N];
ll d[N];
bool st[N];
int n;

inline ll distance(int a, int b) {
    ll dx = x[a] - x[b], dy = y[a] - y[b];
    return dx * dx + dy * dy;
}

ll prim() {
    ll ret = 0;

    // TODO：找到好一点的堆优化写法
    Heap<pair<ll, int>> heap[2];
    for (int i = 1; i < n; ++i) {
        heap[0].push(make_pair(INF, i));
    }
    heap[0].push(make_pair(0ll, 0));

    for (int i = 1; i < n; ++i) {
        int cur = i & 1, pre = cur ^ 1;
        int x = heap[pre].top().second;
        ret = max(ret, heap[pre].top().first);
        heap[pre].pop();

        while (heap[pre].size()) {
            int y = heap[pre].top().second;
            ll dist = heap[pre].top().first;
            heap[pre].pop();
            heap[cur].push(make_pair(min(dist, distance(x, y)), y));
        }
    }

    return max(ret, heap[(n & 1) ^ 1].top().first);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    cout << prim() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}