#include <iostream>

const int N = 2e5 + 10;
int a[N];
int n;

bool check(int val) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (i < j && a[i] == val) ++i;
        while (i < j && a[j] == val) --j;
        if (a[i] != a[j]) return false;
        ++i, --j;
    }
    return true;
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int p = 0, q = n - 1;
    while (p < q) {
        if (a[p] != a[q]) {
            if (check(a[p]) || check(a[q])) {
                puts("YES");
            } else {
                puts("NO");
            }
            return;
        }
        ++p, --q;
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