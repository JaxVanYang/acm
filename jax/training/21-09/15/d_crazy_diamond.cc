#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int p[N], pos[N];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    cout.exceptions(cout.failbit);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    vector<pair<int, int>> ans;

    auto change = [&](int i, int j) {
        swap(p[i], p[j]);
        ans.push_back({i, j});
    };

    for (int i = 1; i <= n; ++i) {
        int j = pos[i];

        if (i == j) continue;
        pos[p[i]] = j;
        // pos[i] = i;

        if (2 * abs(i - j) >= n) {
            change(i, j);
        } else if (i > n / 2) {
            change(1, i);
            change(1, j);
            change(1, i);
        } else if (j <= n / 2) {
            change(i, n);
            change(j, n);
            change(i, n);
        } else {
            change(i, n);
            change(1, n);
            change(1, j);
            change(1, n);
            change(i, n);
        }

    }

    cout << ans.size() << endl;
    for (auto [i, j] : ans) {
        if (i > j) {
            swap(i, j);
        }
        cout << i << ' ' << j << endl;
    }

    // for (int i = 1; i <= n; ++i) {
    //     cout << p[i] << ' ';
    // }
    // cout << endl;
}