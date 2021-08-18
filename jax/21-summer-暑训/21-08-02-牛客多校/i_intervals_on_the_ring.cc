#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define REP(i, l, r) for (int i = l; i < r; ++i)
#define F first
#define S second
#define PF push_fornt
#define PB push_back
#define MP make_pair

const char el = '\n';
const int N = 1e6 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pv;
    REP(_, 0, m) {
        int l, r;
        cin >> l >> r;
        if (l <= r) pv.PB(MP(l, r));
        else {
            pv.PB(MP(1, r));
            pv.PB(MP(l, n));
        }
    }
    sort(pv.begin(), pv.end());
    vector<pair<int, int>> ans;
    int begin = -1, end = -1;
    for (auto &it : pv) {
        if (it.F == end + 1) end = it.S;
        else {
            if (begin != -1 && end != -1)
                ans.PB(MP(begin, end));
            begin = it.F, end = it.S;
        }
    }
    ans.PB(MP(begin, end));
    // for (auto &it : ans) {
    //     cout << "it = " << it.F << ' ' << it.S << el;
    // }
    cout << ans.size() << el;
    for (int i = 0; i < ans.size(); ++i) {
        // cout << "cur = " << i << " nex = " << (i + ans.size() - 1) % n << el;
        cout << ans[i].F << ' ' << ans[(i + ans.size() - 1) % ans.size()].S << el;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
