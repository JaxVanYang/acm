#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 64;
int sgn[N], a[N], b[N], ans[N], zero[N];
int n;

ll f(int *a) {
    ll ret = 0;
    ll k = 1;

    for (int i = 0; i < n; ++i) {
        ret += a[i] * k * sgn[i];
        k <<= 1;
    }

    return ret;
}

ll g(int *a) {
    ll ret = 0;
    ll k = 1;

    for (int i = 0; i < n; ++i) {
        ret += a[i] * k;
        k <<= 1;
    }

    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> sgn[i];
        if (sgn[i] == -1) {
            zero[i] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll sum = f(a) + f(b) + g(zero);

    for (int i = 0; i < n; ++i) {
        ans[i] = (sum >> i) & 1;
    }

    for (int i = 0; i < n; ++i) {
        if (sgn[i] == -1) {
            ans[i] = !ans[i];
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << ans[i] << ' ';
    // }
    cout << ans[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << ans[i];
    }
}