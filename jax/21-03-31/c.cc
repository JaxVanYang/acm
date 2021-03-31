#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }
    int a = y / x;
    ll ans = 0;
    for (ll i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            ll j = a / i;
            if (l <= i * x && i * x <= r && l <= j * x && j * x <= r && __gcd(i, j) == 1) ans += i == j ? 1 : 2;
        }
    }
    cout << ans << endl;
}