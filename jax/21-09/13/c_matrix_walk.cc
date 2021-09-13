#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int n;
int a[N], diff[N];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int l = 0, r = 0, cur = 0;

    set<int> st;
    for (int i = 1; i < n; ++i) {
        diff[i] = a[i] - a[i - 1];
        if (abs(diff[i]) == 1) {
            cur += diff[i];
        }

        l = min(l, cur), r = max(r, cur);

        st.insert(diff[i]);

        if (st.size() > 4) {
            cout << "NO" << endl;
            return 0;
        }
    }

    vector<int> vals;

    for (auto val : st) {
        if (abs(val) != 1) {
            vals.push_back(val);
        }
    }

    if (vals.size() > 2) {
        cout << "NO" << endl;
        return 0;
    }

    if (vals.size() == 2 && abs(vals[0]) != abs(vals[1])) {
        cout << "NO" << endl;
        return 0;
    }

    int x, y;

    if (vals.size() == 0) {
        x = 1, y = 1e9;
    } else {
        y = abs(vals[0]);

        if (y < r - l + 1) {
            cout << "NO" << endl;
            return 0;
        }
        x = 1e9;
    }

    int i = a[0] / y, j = a[0] % y;

    if (a[0] % y == 0) {
        --i;
        j = y;
    }

    // cout << "i = " << i << " j = " << j << endl;;

    for (int k = 1; k < n; ++k) {
        if (diff[k] == 1) {
            ++j;
        } else if (diff[k] == -1) {
            --j;
        } else if (diff[k] > 0) {
            ++i;
        } else {
            --i;
        }

        if (j <= 0 || i < 0 || j > y) {
            cout << "NO" << endl;
            return 0;
        }
        // cout << "i = " << i << " j = " << j << endl;
    }

    cout << "YES" << endl;
    cout << x << ' ' << y << endl;
}