#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<int, int>> ps;

    int ans = 0;
    int l = 0;
    while (l < n) {
        if (s[l] == 'S') {
            ++l;
            continue;
        }

        int r = l;

        while (r < n && s[r] == 'G') {
            ++r;
        }

        // cout << "l = " << l << " r = " << r << endl;

        ps.push_back({l, r});
        ans = max(ans, r - l);
        l = r;
    }

    if (ps.size() > 1) {
        ++ans;
    }

    // cout << "ans = " << ans << endl;

    for (size_t i = 0; i + 1 < ps.size(); ++i) {
        if (ps[i].second + 1 == ps[i + 1].first) {
            int len = ps[i].second - ps[i].first + ps[i + 1].second - ps[i + 1].first;

            // cout << "len = " << len << endl;
            if (ps.size() > 2) {
                ++len;
            }
            ans = max(ans, len);
        }
    }

    cout << ans << endl;
}