#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;

    int diff = abs(a - b);

    for (ll ans = 0; ; ++ans) {
        ll sum = ans * (ans + 1) / 2;

        if (sum >= diff && ((sum ^ diff) & 1) == 0) {
            cout << ans << endl;

            return;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}