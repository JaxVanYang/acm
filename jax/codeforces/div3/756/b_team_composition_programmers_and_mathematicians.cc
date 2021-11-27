#include <iostream>

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);

    int tot = a + b;
    int c = tot / 4;
    if (a >= c && b >= c) {
        printf("%d\n", c);
    } else {
        printf("%d\n", std::min(a, b));
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }
}