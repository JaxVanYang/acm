#include <iostream>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll calc(ll a) {
    ll ret = 0;
    while (a) {
        ret += a % 10;
        a /=10;
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld",&n);
        // cout << "res = " << calc(n) << endl;
        for (ll i = n; i <= 2e18; ++i) {
            if (gcd(i, calc(i)) > 1) {
                printf("%lld\n", i);
                break;
            }
        }
    }
}
