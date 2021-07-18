#include <iostream>
using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    while (n) {
        ans = max(n % 10, ans);
        n /= 10;
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}