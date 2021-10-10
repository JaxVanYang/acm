#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void solve() {
    ans.clear();

    int a, b;
    cin >> a >> b;

    int n = a + b;
    int A = n / 2, B = A;

    if (n & 1) {
        ++A;

        for (int x = max(0, a - A); x <= min(a, B); ++x) {
            ans.push_back(A - a + 2 * x);
        }

        --A, ++B;

        for (int x = max(0, a - A); x <= min(a, B); ++x) {
            ans.push_back(A - a + 2 * x);
        }
    } else {
        for (int x = max(0, a - A); x <= min(a, B); ++x) {
            ans.push_back(A - a + 2 * x);
        }
    }

    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

    cout << ans.size() << endl;

    for (auto it : ans) {
        cout << it << ' ';
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}