#include <iostream>
using namespace std;
using ll = long long;

bool st[100];

void init() {
    st[1] = st[2] = st[4] = st[5] = st[7] = st[8] = true;
    for (int i = 10; i < 100; ++i) {
        if (i % 3 != 0 && i / 10 % 3 != 0 && i % 10 % 3 != 0) {
            st[i] = true;
        }
    }
}

int main() {
    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        ll l, r;
        scanf("%lld%lld", &l, &r);
        ll ans = r - l + 1;
        for (ll i = l; i <= min(99ll, r); ++i) if (st[i]) --ans;
        printf("%lld\n", ans);
    }
}