#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N];
int n;

inline void f(int i) {
    if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
}

bool check() {
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > a[i]) return false;
    }

    return true;
}

void solve() {
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> a[i];

    int i;
    for (i = 1; !check(); ++i) {
        if (i & 1) {
            for (int j = 0; j < n - 1; j += 2) f(j);
        } else {
            for (int j = 1; j < n - 1; j += 2) f(j);
        }
    }

    cout << i - 1 << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}