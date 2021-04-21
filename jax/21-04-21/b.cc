#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        ll k;
        int x;
        scanf("%lld%d", &k, &x);
        ll ans = x + (k - 1) * 9;
        printf("%lld\n", ans);
    }
}