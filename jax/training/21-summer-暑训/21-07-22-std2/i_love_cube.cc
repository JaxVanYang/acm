#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
int g(ll n) {
    ll a = n % mod, b = (n + 1) % mod;
    a = a * a % mod, b = b * b % mod;
    return 2 * a % mod * b % mod;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld", &n);
        int ans = g(n - 1);
        printf("%d\n", ans);
    }
}