#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
vector<int> edges[N];

bool vis[N];

inline void add(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;

        add(u, v);
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    queue<pair<int, double>> q;
    q.push({1, 1.0});
    int dep = 0;
    vis[1] = true;

    double ans = 0.0;

    while (q.size()) {
        int size = q.size();

        while (size--) {
            auto [u, p] = q.front();
            q.pop();

            vector<int> vs;

            for (int v : edges[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    vs.push_back(v);
                }
            }

            if (vs.empty()) {
                ans += dep * p;
            } else {
                double p_ = p / vs.size();
                for (int v : vs) {
                    q.push({v, p_});
                }
            }
        }

        ++dep;
    }

    cout << setprecision(18) << ans << endl;
}