#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

inline ll f(int n, int x) {
    return n / x;
}
inline ll g(int l, int r, int x) {
    return f(r, x) - f(l - 1, x);
}

int main() {
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        ll s1 = b - a + 1, s2 = d - c + 1;
        ll x_2 = g(a, b, 2);
        ll x_1009 = g(a, b, 1009);
        ll x_2018 = g(a, b, 2018);
        ll y_2 = g(c, d, 2);
        ll y_1009 = g(c, d, 1009);
        ll y_2018 = g(c, d, 2018);
        ll ans = 0;
        ans += x_2018 * s2;
        ans += (x_2 - x_2018) * y_1009;
        ans += (x_1009 - x_2018) * y_2;
        ans += (s1 - x_2 - x_1009 + x_2018) * y_2018;
        cout << ans << endl;
    }
}