#include <iostream>
using namespace std;

void solve() {
    int c, r, s;
    scanf("%d%d%d", &c, &r, &s);

    long long rem = c - (s - 1ll) * r;
    int low = rem <= 0 ? 0 : (rem + s - 1) / s;

    int high = c / s;
    rem = (c + r) % s;
    if (c % s + r % s > s || (c % s && r % s == 0)) {
        ++high;
    }

    printf("%d %d\n", high, low);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }
}