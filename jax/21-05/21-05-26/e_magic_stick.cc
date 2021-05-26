#include <iostream>
using namespace std;

inline void yes() {
    puts("YES");
}

inline void no() {
    puts("NO");
}

void solve() {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == y) {
        yes();
    } else if (x == 1) {
        no();
    } else if (x <= 3 && y > 3) {
        no();
    } else {
        yes();
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}