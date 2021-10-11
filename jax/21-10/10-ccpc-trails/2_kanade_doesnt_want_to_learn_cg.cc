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

int a, b, c;

inline ll f(ll x) {
    return a * x * x + b * x + c;
}

void solve() {
    scanf("%d%d%d", &a, &b, &c);
    // cout << "a = " << a << " b = " << b << " c = " << c << endl;

    int x0, x1, y0, y1, y2;
    scanf("%d%d%d%d%d", &x0, &x1, &y0, &y1, &y2);

    ll va = f(x0) - y0, vb = f(x1) - y0;
    // cout << "va = " << va << " vb = " << vb << endl;

    if (va > 0 && vb < 0) {
        puts("Yes");
        return;
    }

    if (va > 0 && vb > 0 && y1 - y0 <= vb && vb <= y2 - y0) {
        ll x = x1 + x1 - x0;

        ll val = f(x) - y0;

        if (val < 0) {
            puts("Yes");
            return;
        }
    }

    puts("No");
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    // cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
