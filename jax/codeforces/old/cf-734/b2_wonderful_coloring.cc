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
const int N = 2e5 + 10;
pi a[N];
int ans[N];

void solve() {
    int n, k;
    cin >> n >> k;
    memset(ans, 0, sizeof(int) * n);

    REP(i, 0, n) {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(a, a + n);
    // REP(i, 0, n) {
    //     cout << "(" << a[i].F << ", " << a[i].S << ") ";
    // }
    // cout << endl;
    int r;
    for (int l = 0; l < n;) {
        r = l;
        if (n - l >= k) {
            // cout << "from " << l << endl;
            REP(i, 0, k) {
                // cout << a[l + i].S << " set to " << 
                ans[a[l + i].S] = i + 1;
            }
            l += k - 1;
            int cnt = 0;
            REP(i, 0, k) {
                if (a[l - i].F != a[l].F) break;
                ++cnt;
            }
            r = l;
            while (r < n && a[r].F == a[l].F) ++r;
            // cout << "cnt = " << cnt << " l + r = " << l + 1 << " bound = " << r - (k - cnt) << endl;
            r = max(l + 1, r - (k - cnt));
            l = r;
            // cout << "to " << l << endl;
        } else {
            ans[a[l++].S] = 0;
        }
    }
    // cout << "ans:" << el;
    REP(i, 0, n) {
        cout << ans[i] << ' ';
    }
    cout << el;
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
