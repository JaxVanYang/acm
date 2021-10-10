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
char s[55];

void solve() {
    cin >> s;
    int n = strlen(s);
    sort(s, s + n);
    int a = 0, b = 0;
    for (int l = 0; l < n;) {
        int r = l;
        while (r < n && s[r] == s[l]) {
            ++r;
        }
        if (r - l > 1) {
            ++a, ++b;
        } else if (a < b) {
            ++a;
        } else {
            ++b;
        }
        l = r;
    }
    cout << min(a, b) << el;
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
