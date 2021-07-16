#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 5e5;

// a: original; b: sorted; c: temporary
int a[N], b[N], c[N];

// lmt: the right bound of b
int n, m, lmt;
ll t;

inline ll f(int x, int y) {
    ll diff = y - x;
    return diff * diff;
}

// merge the old section b[l : lmt] and new new section b[lmt : r] to c[l : r]
void merge(int l, int r) {
    int i = l, j = lmt;
    for (int k = l; k < r; ++k) {
        if (j >= r || (i < lmt && b[i] <= b[j])) {
            c[k] = b[i++];
        } else {
            c[k] = b[j++];
        }
    }
}

ll calc(int l, int r) {
    if (r > n) r = n;
    // cout << "l = " << l << " r = " << r << endl;
    // cout << "lmt = " << lmt << endl;
    ll ret = 0;
    int len = r - l;
    // copy the new section a[lmt : r] to b[lmt : r]
    memcpy(b + lmt, a + lmt, sizeof(int) * (r - lmt));
    sort(b + lmt, b + r);
    merge(l, r);
    for (int i = 0; i < min(m, len / 2); ++i) {
        ret += f(c[l + i], c[r - 1 - i]);
    }
    return ret;
}

void solve() {
    scanf("%d%d%lld", &n, &m, &t);
    lmt = 0;    // b 中已排序的边界
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int cnt = 0;
    int l = 0, r = 0;
    while (l < n) {
        ++cnt;
        int p = 1;
        while (p != 0) {
            // cout << "l = " << l << " r = " << r << " p = " << p << endl;
            ll val = calc(l, r + p);
            // cout << "num = " << val << endl;
            if (val <= t) {
                lmt = r = min(r + p, n);
                if (r == n) break;
                p *= 2;
                memcpy(b + l, c + l, sizeof(int) * (lmt - l));
            } else {
                p /= 2;
            }
        }
        l = r;
    }
    printf("%d\n", cnt);
}

int main() {
    int k;
    scanf("%d", &k);
    while (k--) {
        solve();
    }
}