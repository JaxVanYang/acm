#include <iostream>

const int N = 2e5 + 10;
int a[N];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    if (a[0] != n && a[n - 1] != n) {
        printf("-1");
    } else if (a[0] == n) {
        printf("%d", a[0]);
        for (int i = n - 1; i > 0; --i) {
            printf(" %d", a[i]);
        }
    } else if (a[n - 1] == n) {
        for (int i = n - 2; i >= 0; --i) {
            printf("%d ", a[i]);
        }
        printf("%d", a[n - 1]);
    }
    puts("");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}