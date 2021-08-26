#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> vs(n);
    vector<pair<int, int>> ps(n);
    vector<int> sum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        ps[i].second = k;

        vs[i].resize(k);

        int p = INT32_MIN;

        for (int j = 0; j < k; ++j) {
            cin >> vs[i][j];

            p = max(p, vs[i][j] - j + 1);
        }

        ps[i].first = p;
    }

    sort(ps.begin(), ps.end());

    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + ps[i].second;
    }

    int ans = ps[0].first;

    for (int i = 1; i < n; ++i) {
        ans = max(ans, ps[i].first - sum[i]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}