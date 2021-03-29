#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll a, b, p;
    cin >> a >> b >> p;
    // 方法一
    // ll ans = 0;
    // while (b) {
    //     if (b & 1) {
    //         ans = (ans + a) % p;
    //     }
    //     a = a * 2 % p;
    //     b >>= 1;
    // }
    ll c = (long double)a * b / p;
    ll ans = a * b - c * p;
    // if (ans < 0) ans += p;
    // else if (ans >= p) ans -= p;
    ans %= p;   // 取模运算会根据被除数的符号取值
    cout << ans << endl;
}