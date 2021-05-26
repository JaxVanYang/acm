#include <iostream>
using namespace std;

void solve() {
    int n, x, a, b;
    scanf("%d%d%d%d", &n, &x, &a, &b);
    int dis = abs(a - b);
    if (dis + x > n - 1) {
        printf("%d\n", n - 1);
    } else {
        printf("%d\n", dis + x);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}