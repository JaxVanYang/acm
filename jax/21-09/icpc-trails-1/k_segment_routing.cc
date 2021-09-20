#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const char el = '\n';
vector<int> edges[N];
int path[N];

inline void add(int u, int v) {
    edges[u].push_back(v);
}

void reset(int n) {
    for (int i = 1; i <= n; ++i) {
        edges[i].clear();
    }
}

void calc(bool flag = false) {
    int s, l;
    cin >> s >> l;

    for (int i = 0; i < l; ++i) {
        cin >> path[i];
    }

    for (int i = 0; i < l; ++i) {
        if (edges[s].size() < path[i]) {
            cout << "Packet Loss" << el;
            return;
        }

        s = edges[s][path[i] - 1];
    }

    cout << s << el;
}

void solve(bool flag = false) {
    int n, m;
    cin >> n >> m;

    reset(n);

    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;

        for (int j = 0; j < d; ++j) {
            int v;
            cin >> v;

            add(i, v);
        }
    }

    for (int i = 1; i <= m; ++i) {
        calc(flag && i == m);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit), cout.exceptions(cout.failbit);
    
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << el;

        solve(i == t);
    }
}