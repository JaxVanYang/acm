#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> ps[3];
    int h[3];
    for (int i = 0; i < 3; ++i) {
        cin >> ps[i].first >> ps[i].second;
        h[i] = ps[i].second;
    }

    sort(ps, ps + 3);
    sort(h, h + 3);

    vector<pair<int, int>> ans;

    for (int i = ps[0].first; i <= ps[2].first; ++i) {
        ans.push_back({i, h[1]});
    }

    for (int i = 0; i < 3; ++i) {
        if (ps[i].second > h[1]) {
            for (int j = h[1] + 1; j <= ps[i].second; ++j) {
                ans.push_back({ps[i].first, j});
            }
        } else if (ps[i].second < h[1]) {
            for (int j = ps[i].second; j < h[1]; ++j) {
                ans.push_back({ps[i].first, j});
            }
        }
    }

    cout << ans.size() << endl;
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << endl;
    }
}