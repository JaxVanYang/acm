#include <iostream>
#include <algorithm>
#include <array>

const int N = 2e5 + 10;
std::array<int, N> a;

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    std::sort(a.begin(), a.begin() + n);

    for (int i = 0; i < n / 2; ++i) {
        printf("%d %d\n", a[n - 1 - i], a[0]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}