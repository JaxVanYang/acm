#include <iostream>
using namespace std;
using ll = long long;

inline bool check(double c, double lmt) {
    return c >= lmt;
}

int main() {
    ll n, k;
    scanf("%lld%lld", &n, &k);

    ll ans = -1;
    double lmt = (double)k / 2 * (k + 1);

    for (int i = 1; i <= n / i; ++i) {
        if (n % i == 0) {

            // cout << "i = " << i << " lmt = " << lmt << " n / i = " << n / i << endl;
            if (check(i, lmt)) {
                ans = n / i;
                break;
            }

            if (check(n / i, lmt)) {
                ans = i;
            }            
        }
    }

    // printf("%lld\n", ans);
    if (ans == -1) {
        puts("-1");
        return 0;
    }

    ll sum = k * (k + 1) / 2 - k;
    sum *= ans;
    for (ll i = 1; i < k; ++i) {
        printf("%lld ", i * ans);
    }

    printf("%lld\n", n - sum);
}