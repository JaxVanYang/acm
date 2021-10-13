#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 305;
int d[N];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    sort(d, d + n);
    ll ans = (ll)d[0] * d[n - 1];

    vector<int> c;

    int i = 2;
    for (; i < ans / i; ++i) {
        if (ans % i == 0) {
            c.push_back(i);
            c.push_back(ans / i);
        }
    }
    if ((ll)i * i == ans) {
        c.push_back(i);
    }

    if (n != c.size()) {
        cout << -1 << endl;
        return;
    }

    sort(c.begin(), c.end());

    for (int i = 0; i < n; ++i) {
        if (d[i] != c[i]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}