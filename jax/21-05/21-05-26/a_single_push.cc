#include <iostream>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], b[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) scanf("%d", b + i);
    for (int i = 0; i < n; ++i) {
        a[i] -= b[i];
        if (a[i] > 0) {
            puts("NO");
            return;
        }
    }
    int l = 0;
    bool flag = false;
    while (l < n) {
        while (l < n && a[l] == 0) ++l;
        if (l == n) break;
        if (flag) {
            puts("NO");
            return;
        }
        flag = true;
        int r = l;
        while (r < n && a[r] == a[l]) ++r;
        l = r;
    }
    puts("YES");
}


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}