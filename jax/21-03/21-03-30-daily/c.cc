#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    int a, b;
    cin >> n >> m >> a >> b;
    if (n % m == 0) {
        cout << 0 << endl;
    } else {
        ll x = ((n + m - 1) / m * m - n) * a;
        ll y = n % m * b;
        cout << min(x, y) << endl;
    }
}