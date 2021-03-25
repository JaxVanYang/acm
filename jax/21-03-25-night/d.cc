#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ++n;
    ll ans = n;
    if (n == 1) ans = 0;
    else if ((n & 1) == 0) {
        ans = n / 2;
    }
    // cout << "n = " << n << endl;
    cout << ans << endl;
}