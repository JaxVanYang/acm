#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int a[N];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    set<int> st;

    for (int i = 1; i < n; ++i) {
        int diff = a[i] - a[i - 1];

        // cout << "diff = " << diff << endl;
        
        st.insert(diff);

        if (st.size() > 2) {
            cout << -1 << endl;

            return;
        }
    }

    if (st.size() == 1) {
        cout << 0 << endl;
    } else {
        int x = *st.begin(), y = *(--st.end());

        if (x < 0) swap(x, y);
        // cout << "x = " << x << " y = " << y << endl;

        if (y >= 0) {
            cout << -1 << endl;
            return;
        }

        int m = x - y;

        for (int i = 0; i < n; ++i) {
            if (a[i] >= m) {
                cout << -1 << endl;
                return;
            }
        }

        cout << m << ' ' << x << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}