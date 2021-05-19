#include <iostream>
using namespace std;

const int maxn = 4e5 + 100;

int a[maxn];

inline void no() {
    // cout << "#";
    puts("0 0 0");
}

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    if (n < 6) {
        no();
        return;
    }
    int b = -1;
    for (int i = n / 2 - 1; i >= 0; --i) {
        if (a[i] != a[i + 1]) {
            b = i;
            break;
        }
    }
    int g = 0;
    while (g + 1 < n && a[g + 1] == a[0]) ++g;
    // cout << "g = " << g << " s = " << s << " b = " << b << endl;
    int s = -1, sl = -1, sr = -1;
    for (int i = g + b >> 1; i >= 0; --i) {
        if (a[i] != a[i + 1]) {
            sl = i;
            break;
        }
    }
    for (int i = g + b >> 1; i < b; ++i) {
        if (a[i] != a[i + 1]) {
            sr = i;
            break;
        }
    }
    if (min(sl - g, b - sl) > min(sr - g, b - sr)) {
        s = sl;
    } else {
        s = sr;
    }
    if (g < s && s < b && g + 1 < min(s - g, b - s)) {
        // cout << "#";
        printf("%d %d %d\n", g + 1, s - g, b - s);
    } else {
        no();
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}