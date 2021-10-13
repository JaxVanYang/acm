#include <iostream>
using namespace std;

void solve() {
    int c, r, s;
    scanf("%d%d%d", &c, &r, &s);

    int x = (c + r) / s;
    int y = (c + r) % s;
    int s1 = c / s, s2;

    if (y != 0 && c % s >= y) s1++;
    
    if (y != 0) ++x;

    if (x <= r) s2 = 0;
    else s2 = x - r;
    
    printf("%d %d\n", s1, s2);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }
}