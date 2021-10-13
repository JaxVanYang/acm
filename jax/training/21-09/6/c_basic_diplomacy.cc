#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

vector<int> f[N], g[N];
int d[N], ans[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        d[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;

        f[i].resize(k);

        for (int j = 0; j < k; ++j) {
            cin >> f[i][j];

            g[f[i][j]].push_back(i);
        }
    }

    int id = 0, max_d = 0;

    for (int i = 0; i < m; ++i) {
        int p = f[i].front();

        ans[i] = p;

        d[p]++;

        if (d[p] > max_d) {
            id = p, max_d = d[p];
        }
    }

    if (max_d > (m + 1) / 2) {
        vector<int> days;

        for (int i = 0; i < m; ++i) {
            if (ans[i] == id) {
                days.push_back(i);
            }
        }

        for (int day : days) {
            for (int v : f[day]) {
                if (v == id) continue;

                ans[day] = v;

                d[id]--;
                d[v]++;

                break;
            }
            if (d[id] <= (m + 1) / 2) break;
        }
    }

    if (d[id] > (m + 1) / 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        for (int i = 0; i < m; ++i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}