#include <bits/stdc++.h>
using namespace std;
const int N = 30050;

int head[N], nex[N], ver[N], tot = 0;
int deg[N];
int a[N], len = 0;
bitset<N> f[N];

void add(int u, int v) {
    ver[++tot] = v, nex[tot] = head[u], head[u] = tot;
    deg[v]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (auto &it : v) {
        add(it.first, it.second);
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) q.push(i);
    }
    // cout << "q.size = " << q.size() << endl;

    while (q.size()) {
        int x = q.front();
        // cout << "x = " << x << endl;
        q.pop();
        a[len++] = x;

        for (int i = head[x]; i; i = nex[i]) {
            int y = ver[i];
            if (--deg[y] == 0) q.push(y);
        }
    }

    // for (int i = 0; i < len; ++i) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;

    for (int i = len - 1; i >= 0; --i) {
        int x = a[i];
        f[x][x] = 1;
        for (int j = head[x]; j; j = nex[j]) {
            int y = ver[j];
            f[x] |= f[y];
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << f[i].count() << endl;
    }
}