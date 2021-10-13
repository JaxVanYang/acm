#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int n;
ll x[N];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    sort(x, x + n);

    vector<ll> ans{x[0]};

    for (int i = 0; i < n; ++i) {
        for (int bit = 0; bit < 32; ++bit) {
            ll val = 1ll << bit;

            int j = lower_bound(x + i + 1, x + n, x[i] + val) - x;

            if (j != n && x[j] == x[i] + val) {

                if (ans.size() == 1) {
                    ans = {x[i], x[j]};
                }

                int k = lower_bound(x + j + 1, x + n, x[j] + val) - x;

                if (k != n && x[k] == x[j] + val) {
                    ans = {x[i], x[j], x[k]};
                    goto ANS;
                }
            }
        }
    }

    ANS:
    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it << ' ';
    }
    cout << endl;
}