#include <iostream>
using namespace std;

void solve() {
    int l, r;
    scanf("%d%d", &l, &r);
    int cnt = r - l + 1;
    int ans = 0;
    if (cnt & 1) {
        ans += l & 1 ? -l : l;
        ++l;
        --cnt;
    }
    if (l & 1) {
        ans += cnt / 2;
    } else {
        ans -= cnt / 2;
    }
    printf("%d\n", ans);
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        solve();
    }
}