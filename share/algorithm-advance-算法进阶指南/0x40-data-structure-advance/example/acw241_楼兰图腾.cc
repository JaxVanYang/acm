#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int n, y[N], c[N], lft[2][N], rht[2][N];

inline int lowbit(int x) {
    return x & -x;
}

void add(int x, int y = 1) {
    for (; x <= n; x += lowbit(x)) {
        c[x] += y;
    }
}

int ask(int x) {
    int ret = 0;
    while (x) {
        int low = lowbit(x);
        ret += c[x];
        x -= low;
    }
    return ret;
}

inline int ask(int l, int r) {
    return ask(r) - ask(l - 1);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> y[i];
    }

    for (int i = 1; i <= n; ++i) {
        lft[0][i] = ask(1, y[i]);
        lft[1][i] = ask(y[i], n);

        // cout << "l[" << i << "] = " << lft[0][i] << " " << lft[1][i] << endl;

        add(y[i]);
    }

    fill(c + 1, c + n + 1, 0);
    // memset(c, 0, sizeof c);

    for (int i = n; i >= 1; --i) {
        rht[0][i] = ask(1, y[i]);
        rht[1][i] = ask(y[i], n);
        add(y[i]);
    }

    ll cnt[2] = {0, 0};

    for (int i = 1; i <= n; ++i) {
        cnt[0] += (ll)lft[1][i] * rht[1][i];
        cnt[1] += (ll)lft[0][i] * rht[0][i];

        // cout << "cnt[0] = " << cnt[0] << " cnt[1] = " << cnt[1] << endl;
    }

    cout << cnt[0] << ' ' << cnt[1] << endl;
}