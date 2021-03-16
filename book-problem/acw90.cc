#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ll a, b, p;
    cin >> a >> b >> p;
    ll ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    cout << ans << endl;
}