#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

// int f(int i) {
//     if (i == 1) return 0;
//     return 8 + 8 * f(i - 1);
// }

int g(ll n) {
    ll a = n % mod, b = (n + 1) % mod;
    a = a * a % mod, b = b * b % mod;
    return 2 * a % mod * b % mod;
}

// int quick(ll n) {

// }

int main() {


    // for (int i = 1; i < 10; ++i) cout << g(i) << endl;

    int t;
    scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld", &n);
        int ans = g(n - 1);
        printf("%d\n", ans);
    }
}