#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
using ll = long long;

const int maxn = 5e5 + 5;
// a: original array; b: array used for calculation; c: temporary array
int a[maxn], b[maxn], c[maxn];

ll calc(int l, int r, int m) {
    ll ret = 0;
    while (m-- && l < r) {
        ret += pow(b[l++] - b[r--], 2);
    }
    return ret;
}

void merge(int l, int r, int p) {
    // (r, r + p] is on the right of the section, so no need to worry about that merging would cover
    // (r, r + p] is the new section, so it's from original array a
    memcpy(b + r + 1, a + r + 1, sizeof(int) * p);
    // [l, r] is on the left, so it must be copied to temporary array c
    // b[l, r] is maintained to be always sorted.
    memcpy(c + l, b + l, sizeof(int) * (r - l + 1));
    
    sort(b + r + 1, b + r + p + 1);
    int i = l, j = r + 1, k = l;
    for (; i <= r && j <= r + p; ++k) {
        if (c[i] < b[j]) {
            b[k] = c[i++];
        } else {
            b[k] = b[j++];
        }
    }
    while (i <= r) {
        b[k++] = c[i++];
    }
}

void solve() {
    int n, m;
    ll t;
    scanf("%d%d%lld", &n, &m, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int cnt = 0;
    int l = 0;
    while (l < n) {
        int p = 1, r = l;
        // Note: Don't forget this!
        b[l] = a[l];
        ++cnt;
        // cout << "l = " << l << endl;
        while (p != 0) {
            if (r + p >= n) {
                merge(l, r, n - r - 1);
                if (calc(l, n - 1, m) <= t) {
                    r = n - 1;
                    break;
                }
                memcpy(b + l, c + l, sizeof(int) * (r - l + 1));
                p /= 2;
            }
            merge(l, r, p);
            if (calc(l, r + p, m) <= t) {
                r += p;
                p *= 2;
            } else {
                memcpy(b + l, c + l, sizeof(int) * (r - l + 1));
                p /= 2;
            }
        }
        // cout << "r = " << r << endl;
        l = r + 1;
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